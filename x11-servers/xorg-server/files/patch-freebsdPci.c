--- hw/xfree86/os-support/bus/freebsdPci.c.orig	Thu Sep  6 02:48:26 2007
+++ hw/xfree86/os-support/bus/freebsdPci.c	Sat Sep 29 12:22:56 2007
@@ -109,10 +109,6 @@
 #define PCI_CPU(val)	(val)
 #endif
 
-
-#define BUS(tag) (((tag)>>16)&0xff)
-#define DFN(tag) (((tag)>>8)&0xff)
-
 static int pciFd = -1;
 
 void
@@ -133,9 +129,12 @@
 {
 	struct pci_io io;
 	int error;
-	io.pi_sel.pc_bus = BUS(tag);
-	io.pi_sel.pc_dev = DFN(tag) >> 3;
-	io.pi_sel.pc_func = DFN(tag) & 7;
+#ifndef INCLUDE_XF86_NO_DOMAIN
+	io.pi_sel.pc_domain = PCI_DOM_FROM_TAG(tag);
+#endif
+	io.pi_sel.pc_bus = PCI_BUS_NO_DOMAIN(PCI_BUS_FROM_TAG(tag));
+	io.pi_sel.pc_dev = PCI_DEV_FROM_TAG(tag);
+	io.pi_sel.pc_func = PCI_FUNC_FROM_TAG(tag);
 	io.pi_reg = off;
 	io.pi_width = 4;
 	error = ioctl(pciFd, PCIOCREAD, &io);
@@ -148,9 +147,12 @@
 freebsdPciCfgWrite(PCITAG tag, int off, CARD32 val)
 {
 	struct pci_io io;
-	io.pi_sel.pc_bus = BUS(tag);
-	io.pi_sel.pc_dev = DFN(tag) >> 3;
-	io.pi_sel.pc_func = DFN(tag) & 7;
+#ifndef INCLUDE_XF86_NO_DOMAIN
+	io.pi_sel.pc_domain = PCI_DOM_FROM_TAG(tag);
+#endif
+	io.pi_sel.pc_bus = PCI_BUS_NO_DOMAIN(PCI_BUS_FROM_TAG(tag));
+	io.pi_sel.pc_dev = PCI_DEV_FROM_TAG(tag);
+	io.pi_sel.pc_func = PCI_FUNC_FROM_TAG(tag);
 	io.pi_reg = off;
 	io.pi_width = 4;
 	io.pi_data = PCI_CPU(val);
@@ -164,3 +166,260 @@
 	val = (val & ~mask) | (bits & mask);
 	freebsdPciCfgWrite(tag, off, val);
 }
+
+#ifndef INCLUDE_XF86_NO_DOMAIN
+
+/* This probably shouldn't be FreeBSD-specific. */
+static pciConfigPtr
+xf86GetPciHostConfigFromTag(PCITAG Tag)
+{
+	int bus = PCI_BUS_FROM_TAG(Tag);
+	pciBusInfo_t *pBusInfo;
+
+	while ((bus < pciNumBuses) && (pBusInfo = pciBusInfo[bus])) {
+		if (bus == pBusInfo->primary_bus)
+			return pBusInfo->bridge;
+		bus = pBusInfo->primary_bus;
+	}
+
+	return NULL;	/* Bad data */
+}
+
+/*
+ * This is ugly, but until I can extract this information from the kernel,
+ * it'll have to do. The default I/O space size is 64K, and 4G for memory.
+ * Anything else needs to go in this table. (PowerPC folk take note.)
+ *
+ * Please keep this table in ascending vendor/device order.
+ */
+static const struct pciSizes {
+	unsigned short vendor, device;
+	unsigned long io_size, mem_size;
+} pciControllerSizes[] = {
+	{
+		PCI_VENDOR_SUN, PCI_CHIP_PSYCHO,
+		1U << 16, 1U << 31
+	},
+	{
+		PCI_VENDOR_SUN, PCI_CHIP_SCHIZO,
+		1U << 24, 1U << 31	/* ??? */
+	},
+	{
+		PCI_VENDOR_SUN, PCI_CHIP_SABRE,
+		1U << 24, (unsigned long)(1ULL << 32)
+	},
+	{
+		PCI_VENDOR_SUN, PCI_CHIP_HUMMINGBIRD,
+		1U << 24, (unsigned long)(1ULL << 32)
+	}
+};
+#define NUM_SIZES (sizeof(pciControllerSizes) / sizeof(pciControllerSizes[0]))
+
+static const struct pciSizes *
+freebsdGetSizesStruct(PCITAG Tag)
+{
+	static const struct pciSizes default_size = {
+		0, 0, 1U << 16, (unsigned long)(1ULL << 32)
+	};
+	pciConfigPtr pPCI;
+	int i;
+
+	/* Find host bridge */
+	if ((pPCI = xf86GetPciHostConfigFromTag(Tag))) {
+		/* Look up vendor/device */
+		for (i = 0; i < NUM_SIZES; i++) {
+			if ((pPCI->pci_vendor ==
+			    pciControllerSizes[i].vendor) &&
+			    (pPCI->pci_device ==
+			    pciControllerSizes[i].device)) {
+				return & pciControllerSizes[i];
+			}
+		}
+	}
+
+	/* Default to 64KB I/O and 4GB memory. */
+	return & default_size;
+}
+
+static __inline__ unsigned long
+freebsdGetIOSize(PCITAG Tag)
+{
+	const struct pciSizes * const sizes = freebsdGetSizesStruct(Tag);
+	return sizes->io_size;
+}
+
+static __inline__ void
+freebsdGetSizes(PCITAG Tag, unsigned long *io_size, unsigned long *mem_size)
+{
+	const struct pciSizes * const sizes = freebsdGetSizesStruct(Tag);
+
+	*io_size = sizes->io_size;
+	*mem_size = sizes->mem_size;
+}
+
+_X_EXPORT int
+xf86GetPciDomain(PCITAG Tag)
+{
+	return PCI_DOM_FROM_TAG(Tag);
+}
+
+_X_EXPORT pointer
+xf86MapDomainMemory(int ScreenNum, int Flags, PCITAG Tag, ADDRESS Base,
+    unsigned long Size)
+{
+	return xf86MapVidMem(ScreenNum, Flags, Base, Size);
+}
+
+_X_EXPORT IOADDRESS
+xf86MapDomainIO(int ScreenNum, int Flags, PCITAG Tag, IOADDRESS Base,
+    unsigned long Size)
+{
+	return Base;
+}
+
+_X_EXPORT int
+xf86ReadDomainMemory(PCITAG Tag, ADDRESS Base, int Len, unsigned char *Buf)
+{
+	int ret, length, rlength;
+
+	/* Read in 64kB chunks. */
+	ret = 0;
+	while ((length = Len) > 0) {
+		if (length > 0x010000) length = 0x010000;
+		rlength = xf86ReadBIOS(Base, 0, Buf, length);
+		if (rlength < 0) {
+			ret = rlength;
+			break;
+		}
+		ret += rlength;
+		if (rlength < length) break;
+		Base += rlength;
+		Buf += rlength;
+		Len -= rlength;
+	}
+
+	return ret;
+}
+
+resPtr
+xf86BusAccWindowsFromOS(void)
+{
+	pciConfigPtr *ppPCI, pPCI;
+	resPtr pRes = NULL;
+	resRange range;
+	unsigned long io_size, mem_size;
+	int domain;
+
+	if ((ppPCI = xf86scanpci(0))) {
+		for (; (pPCI = *ppPCI); ppPCI++) {
+			if ((pPCI->pci_base_class != PCI_CLASS_BRIDGE) ||
+			    (pPCI->pci_sub_class != PCI_SUBCLASS_BRIDGE_HOST))
+				continue;
+
+			domain = xf86GetPciDomain(pPCI->tag);
+			freebsdGetSizes(pPCI->tag, &io_size, &mem_size);
+
+			RANGE(range, 0, (ADDRESS)(mem_size - 1),
+			    RANGE_TYPE(ResExcMemBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+
+			RANGE(range, 0, (IOADDRESS)(io_size - 1),
+			    RANGE_TYPE(ResExcIoBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+
+			if (domain <= 0)
+				break;
+		}
+	}
+
+	return pRes;
+}
+
+resPtr
+xf86PciBusAccWindowsFromOS(void)
+{
+	pciConfigPtr *ppPCI, pPCI;
+	resPtr pRes = NULL;
+	resRange range;
+	unsigned long io_size, mem_size;
+	int domain;
+
+	if ((ppPCI = xf86scanpci(0))) {
+		for (; (pPCI = *ppPCI); ppPCI++) {
+			if ((pPCI->pci_base_class != PCI_CLASS_BRIDGE) ||
+			    (pPCI->pci_sub_class != PCI_SUBCLASS_BRIDGE_HOST))
+				continue;
+
+			domain = xf86GetPciDomain(pPCI->tag);
+			freebsdGetSizes(pPCI->tag, &io_size, &mem_size);
+
+			RANGE(range, 0, (ADDRESS)(mem_size - 1),
+			    RANGE_TYPE(ResExcMemBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+
+			RANGE(range, 0, (IOADDRESS)(io_size - 1),
+			    RANGE_TYPE(ResExcIoBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+
+			if (domain <= 0)
+				break;
+		}
+	}
+
+	return pRes;
+}
+
+resPtr
+xf86AccResFromOS(resPtr pRes)
+{
+	pciConfigPtr *ppPCI, pPCI;
+	resRange range;
+	unsigned long io_size, mem_size;
+	int domain;
+
+	if ((ppPCI = xf86scanpci(0))) {
+		for (; (pPCI = *ppPCI); ppPCI++) {
+			if ((pPCI->pci_base_class != PCI_CLASS_BRIDGE) ||
+			    (pPCI->pci_sub_class != PCI_SUBCLASS_BRIDGE_HOST))
+				continue;
+
+			domain = xf86GetPciDomain(pPCI->tag);
+			freebsdGetSizes(pPCI->tag, &io_size, &mem_size);
+
+			/*
+			 * At minimum, the top and bottom resources must be
+			 * claimed, so that resources that are (or appear to
+			 * be) unallocated can be relocated.
+			 */
+			RANGE(range, 0x00000000u, 0x0009ffffu,
+			    RANGE_TYPE(ResExcMemBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+			RANGE(range, 0x000c0000u, 0x000effffu,
+			    RANGE_TYPE(ResExcMemBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+			RANGE(range, 0x000f0000u, 0x000fffffu,
+			    RANGE_TYPE(ResExcMemBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+
+			RANGE(range, (ADDRESS)(mem_size - 1),
+			    (ADDRESS)(mem_size - 1),
+			    RANGE_TYPE(ResExcMemBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+
+			RANGE(range, 0x00000000u, 0x00000000u,
+			    RANGE_TYPE(ResExcIoBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+			RANGE(range, (IOADDRESS)(io_size - 1),
+			    (IOADDRESS)(io_size - 1),
+			    RANGE_TYPE(ResExcIoBlock, domain));
+			pRes = xf86AddResToList(pRes, &range, -1);
+
+			if (domain <= 0)
+				break;
+		}
+	}
+
+	return pRes;
+}
+
+#endif /* !INCLUDE_XF86_NO_DOMAIN */

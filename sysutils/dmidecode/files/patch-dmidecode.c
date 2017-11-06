--- dmidecode.c.orig	2017-05-23 13:34:14 UTC
+++ dmidecode.c
@@ -58,6 +58,10 @@
  *    https://trustedcomputinggroup.org/pc-client-platform-tpm-profile-ptp-specification/
  */
 
+#ifdef __FreeBSD__
+#include <errno.h>
+#include <kenv.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <strings.h>
@@ -4934,13 +4938,18 @@ static int legacy_decode(u8 *buf, const 
 #define EFI_NO_SMBIOS   (-2)
 static int address_from_efi(off_t *address)
 {
+#if defined(__linux__)
 	FILE *efi_systab;
 	const char *filename;
 	char linebuf[64];
+#elif defined(__FreeBSD__)
+	char addrstr[KENV_MVALLEN + 1];
+#endif
 	int ret;
 
 	*address = 0; /* Prevent compiler warning */
 
+#if defined(__linux__)
 	/*
 	 * Linux up to 2.6.6: /proc/efi/systab
 	 * Linux 2.6.7 and up: /sys/firmware/efi/systab
@@ -4973,6 +4982,25 @@ static int address_from_efi(off_t *addre
 	if (ret == EFI_NO_SMBIOS)
 		fprintf(stderr, "%s: SMBIOS entry point missing\n", filename);
 	return ret;
+#elif defined(__FreeBSD__)
+	/*
+	 * On FreeBSD, SMBIOS anchor base address in UEFI mode is exposed
+	 * via kernel environment:
+	 * https://svnweb.freebsd.org/base?view=revision&revision=307326
+	 */
+	ret = kenv(KENV_GET, "hint.smbios.0.mem", addrstr, sizeof(addrstr));
+	if (ret == -1) {
+		if (errno != ENOENT)
+			perror("kenv");
+		return EFI_NOT_FOUND;
+	}
+
+	*address = strtoull(addrstr, NULL, 0);
+	if (!(opt.flags & FLAG_QUIET))
+		printf("# SMBIOS entry point at 0x%08llx\n",
+		    (unsigned long long)*address);
+	return 0;
+#endif
 }
 
 int main(int argc, char * const argv[])

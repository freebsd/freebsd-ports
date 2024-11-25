--- src/detection/gpu/gpu_pci.c.orig	2024-11-18 06:57:05 UTC
+++ src/detection/gpu/gpu_pci.c
@@ -39,7 +39,7 @@ static const FFstrbuf* loadPciIds()
         }
         #elif __FreeBSD__
         // https://github.com/freebsd/freebsd-src/blob/main/usr.sbin/pciconf/pathnames.h
-        ffReadFileBuffer(_PATH_LOCALBASE "/share/pciids/pci.ids", &pciids);
+        ffReadFileBuffer(_PATH_LOCALBASE "/share/hwdata/pci.ids", &pciids);
         if (pciids.length == 0)
             ffReadFileBuffer(FASTFETCH_TARGET_DIR_USR "/share/pciids/pci.ids", &pciids);
         #elif __sun

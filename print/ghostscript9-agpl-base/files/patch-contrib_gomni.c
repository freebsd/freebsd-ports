--- contrib/gomni.c.orig	2015-03-30 08:21:24 UTC
+++ contrib/gomni.c
@@ -530,7 +530,7 @@ CloseDevice (gx_device * pdev)
       && pDev->pcoreOmni->pszJobOptions
       )
    {
-      gs_free (pDev->memory->non_gc_memory, pDev->pcoreOmni->pszJobOptions, strlen (pDev->pcoreOmni->pszJobOptions) + 1, 1, "Option String");
+      gs_free (gs_lib_ctx_get_non_gc_memory_t(), pDev->pcoreOmni->pszJobOptions, strlen (pDev->pcoreOmni->pszJobOptions) + 1, 1, "Option String");
    }
 
    if (  pDev->pcoreOmni
@@ -549,7 +549,7 @@ CloseDevice (gx_device * pdev)
 
    if (pDev->pcoreOmni)
    {
-      gs_free (pDev->memory->non_gc_memory, pDev->pcoreOmni, sizeof (core_omni_device), 1, "omni/device");
+      gs_free (gs_lib_ctx_get_non_gc_memory_t(), pDev->pcoreOmni, sizeof (core_omni_device), 1, "omni/device");
       pDev->pcoreOmni = 0;
    }
 
@@ -720,7 +720,7 @@ SetupDevice (gx_device *pgxdev, gs_param
    {
       PDEVSTRUCT p;
 
-      p = (PDEVSTRUCT)gs_malloc (pgxdev->memory->non_gc_memory, 1, sizeof (Omni_Dev), "omni/instance");
+      p = (PDEVSTRUCT)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1, sizeof (Omni_Dev), "omni/instance");
       if (!p)
       {
           dprintf ("<<<<<<<<<<<<<<<<<<<<<< ERROR >>>>>>>>>>>>>>>>>>>>>>>\n\n");
@@ -734,7 +734,7 @@ SetupDevice (gx_device *pgxdev, gs_param
 
       memset (pDev, 0, sizeof (Omni_Dev));
 
-      pDev->pcoreOmni = (core_omni_device *)gs_malloc (pgxdev->memory->non_gc_memory, 1, sizeof (core_omni_device), "omni/device");
+      pDev->pcoreOmni = (core_omni_device *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1, sizeof (core_omni_device), "omni/device");
 
       if (!pDev->pcoreOmni)
       {
@@ -783,7 +783,7 @@ SetupDevice (gx_device *pgxdev, gs_param
 
       for (i = 0; i < sizeof (apszLibraryPaths)/sizeof (apszLibraryPaths[0]) && !pDev->hmodOmni; i++)
       {
-          pszDeviceLib = (char *)gs_malloc (pDev->memory->non_gc_memory, 1,
+          pszDeviceLib = (char *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1,
                                             strlen (cOmnilib)
                                             + strlen (apszLibraryPaths[i])
                                             + 1,
@@ -796,7 +796,7 @@ SetupDevice (gx_device *pgxdev, gs_param
 
               if (fDebugOutput) dprintf2 ("SetupDevice: Trying to load %s = %p\n", pszDeviceLib, pDev->hmodOmni);
           }
-          gs_free (pDev->memory->non_gc_memory, pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
+          gs_free (gs_lib_ctx_get_non_gc_memory_t(), pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
       }
 
       if (!pDev->hmodOmni)
@@ -810,7 +810,7 @@ SetupDevice (gx_device *pgxdev, gs_param
 
          for (i = 0; i < sizeof (apszLibraryPaths)/sizeof (apszLibraryPaths[0]) && !pDev->hmodOmni; i++)
          {
-             pszDeviceLib = (char *)gs_malloc (pDev->memory->non_gc_memory, 1,
+             pszDeviceLib = (char *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1,
                                                strlen (cOmnilib)
                                                + strlen (apszLibraryPaths[i])
                                                + 1,
@@ -830,7 +830,7 @@ SetupDevice (gx_device *pgxdev, gs_param
                     g_module_close (pModule);
                  }
              }
-             gs_free (pDev->memory->non_gc_memory, pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
+             gs_free (gs_lib_ctx_get_non_gc_memory_t(), pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
          }
 
          return 1;
@@ -953,7 +953,7 @@ SetupDevice (gx_device *pgxdev, gs_param
          )
       {
          if (!pDev->pcoreOmni->pszJobOptions)
-            pDev->pcoreOmni->pszJobOptions = (char *)gs_malloc (pDev->memory->non_gc_memory, 1, fname.size + 1, "Option String");
+            pDev->pcoreOmni->pszJobOptions = (char *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1, fname.size + 1, "Option String");
          memcpy (pDev->pcoreOmni->pszJobOptions, fname.data, fname.size);
          pDev->pcoreOmni->pszJobOptions[fname.size] = '\0';
       }
@@ -1044,7 +1044,7 @@ SetupDevice (gx_device *pgxdev, gs_param
 
          for (i = 0; i < sizeof (apszLibraryPaths)/sizeof (apszLibraryPaths[0]) && !pModule; i++)
          {
-            pszDeviceLib = (char *)gs_malloc (pDev->memory->non_gc_memory, 1,
+            pszDeviceLib = (char *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1,
                                               strlen (cDialogName)
                                               + strlen (apszLibraryPaths[i])
                                               + 1,
@@ -1059,7 +1059,7 @@ SetupDevice (gx_device *pgxdev, gs_param
 
                 pModule = g_module_open (pszDeviceLib, (GModuleFlags)0);
             }
-            gs_free (pDev->memory->non_gc_memory, pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
+            gs_free (gs_lib_ctx_get_non_gc_memory_t(), pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
          }
 
          if (!pModule)
@@ -1070,7 +1070,7 @@ SetupDevice (gx_device *pgxdev, gs_param
 
             for (i = 0; i < sizeof (apszLibraryPaths)/sizeof (apszLibraryPaths[0]) && !pModule; i++)
             {
-               pszDeviceLib = (char *)gs_malloc (pDev->memory->non_gc_memory, 1,
+               pszDeviceLib = (char *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1,
                                                  strlen (cDialogName)
                                                  + strlen (apszLibraryPaths[i])
                                                  + 1,
@@ -1092,7 +1092,7 @@ SetupDevice (gx_device *pgxdev, gs_param
                       g_module_close (pModule);
                    }
                }
-               gs_free (pDev->memory->non_gc_memory, pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
+               gs_free (gs_lib_ctx_get_non_gc_memory_t(), pszDeviceLib, strlen (pszDeviceLib) + 1, 1, "Devicestring");
             }
          }
          else
@@ -1107,13 +1107,13 @@ SetupDevice (gx_device *pgxdev, gs_param
 
                if (pDev->pcoreOmni->pszJobOptions)
                {
-                  gs_free (pDev->memory->non_gc_memory, pDev->pcoreOmni->pszJobOptions, strlen (pDev->pcoreOmni->pszJobOptions) + 1, 1, "Option String");
+                  gs_free (gs_lib_ctx_get_non_gc_memory_t(), pDev->pcoreOmni->pszJobOptions, strlen (pDev->pcoreOmni->pszJobOptions) + 1, 1, "Option String");
                   pDev->pcoreOmni->pszJobOptions = 0;
                }
 
                iLength = strlen (pszSelectedJobProperties);
 
-               pDev->pcoreOmni->pszJobOptions = (char *)gs_malloc (pDev->memory->non_gc_memory, 1, iLength + 1, "Option String");
+               pDev->pcoreOmni->pszJobOptions = (char *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1, iLength + 1, "Option String");
 
                strcpy (pDev->pcoreOmni->pszJobOptions, pszSelectedJobProperties);
 
@@ -1375,7 +1375,7 @@ PrintPage (gx_device_printer *pgx_prt_de
       iBytesToAlloc += (iNumColors - 1) * sizeof (RGB2);
    }
 
-   pbmi = (PBITMAPINFO2)gs_malloc (pDev->memory->non_gc_memory, 1, iBytesToAlloc, "Bmpi Memory");
+   pbmi = (PBITMAPINFO2)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1, iBytesToAlloc, "Bmpi Memory");
    if (!pbmi)
    {
       eprintf("<<<<<<<<<<<<<<<<<<<<<< ERROR >>>>>>>>>>>>>>>>>>>>>>>\n\n");
@@ -1481,7 +1481,7 @@ PrintPage (gx_device_printer *pgx_prt_de
       }
    }
 
-   pGSData = (byte *)gs_malloc (pDev->memory->non_gc_memory, uiBytesPerLine, 1, "bmp file buffer");
+   pGSData = (byte *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), uiBytesPerLine, 1, "bmp file buffer");
 
    if (pGSData == 0)
       /* can't allocate row buffer */
@@ -1501,7 +1501,7 @@ PrintPage (gx_device_printer *pgx_prt_de
                                 pasyncDev->pDev->iVertDots,
                                 8000*1024);                 /*eight meg buffer */
 
-   pBitmapMem = (byte *) gs_malloc (pDev->memory->non_gc_memory, 1, uiBytesPerLine * ulBandLength, "Bitmap Memory");
+   pBitmapMem = (byte *) gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1, uiBytesPerLine * ulBandLength, "Bitmap Memory");
 
    if(!pBitmapMem)
    {
@@ -1613,7 +1613,7 @@ PrintPage (gx_device_printer *pgx_prt_de
             {
                if (prtMode.iBitCount < 16)
                {
-                  pMonoData = (byte *)gs_malloc (pDev->memory->non_gc_memory, 1, iYBand * ImageInfo.ulTrgBytesPerLine, "Mono Memory");
+                  pMonoData = (byte *)gs_malloc (gs_lib_ctx_get_non_gc_memory_t(), 1, iYBand * ImageInfo.ulTrgBytesPerLine, "Mono Memory");
 
                   if (pMonoData)
                   {
@@ -1661,7 +1661,7 @@ PrintPage (gx_device_printer *pgx_prt_de
                /* We're done with the mono band */
                /* now free up the mono buffer so we can get clean data buffer if more lines are to be */
                /* gray-scaled */
-               gs_free (pDev->memory->non_gc_memory, (char *)pMonoData, iYBand * ImageInfo.ulTrgBytesPerLine, 1, "Mono Memory");
+               gs_free (gs_lib_ctx_get_non_gc_memory_t(), (char *)pMonoData, iYBand * ImageInfo.ulTrgBytesPerLine, 1, "Mono Memory");
 
                pMonoData = NULL;
             }
@@ -1709,11 +1709,11 @@ PrintPage (gx_device_printer *pgx_prt_de
 
 done:
 
-   gs_free (pDev->memory->non_gc_memory, (char *) pBitmapMem, uiBytesPerLine * ulBandLength, 1, "Bitmap Memory");
+   gs_free (gs_lib_ctx_get_non_gc_memory_t(), (char *) pBitmapMem, uiBytesPerLine * ulBandLength, 1, "Bitmap Memory");
    dprintf ("Page Completed\n");
 
-   gs_free (pDev->memory->non_gc_memory, (char *)pGSData, uiBytesPerLine, 1, "bmp file buffer");
-   gs_free (pDev->memory->non_gc_memory, (char *)pbmi, uiBytesPerLine, 1, "Bpmi Memory");
+   gs_free (gs_lib_ctx_get_non_gc_memory_t(), (char *)pGSData, uiBytesPerLine, 1, "bmp file buffer");
+   gs_free (gs_lib_ctx_get_non_gc_memory_t(), (char *)pbmi, uiBytesPerLine, 1, "Bpmi Memory");
 
    /******************************************************************/
    /* Note:                                         @@08162000       */

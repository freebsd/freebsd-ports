--- src/wcmValidateDevice.c.orig	2015-10-23 17:26:33 UTC
+++ src/wcmValidateDevice.c
@@ -34,6 +34,7 @@ static Bool wcmCheckSource(InputInfoPtr 
 {
 	int match = 0;
 	InputInfoPtr pDevices = xf86FirstLocalDevice();
+	char* fsource = xf86CheckStrOption(pInfo->options, "_source", "");
 
 	for (; !match && pDevices != NULL; pDevices = pDevices->next)
 	{
@@ -51,7 +52,6 @@ static Bool wcmCheckSource(InputInfoPtr 
 		if (pInfo != pDevices)
 		{
 			WacomCommonPtr pCommon = ((WacomDevicePtr)pDevices->private)->common;
-			char* fsource = xf86CheckStrOption(pInfo->options, "_source", "");
 			char* psource = xf86CheckStrOption(pDevices->options, "_source", "");
 
 			if (pCommon->min_maj &&
@@ -62,10 +62,11 @@ static Bool wcmCheckSource(InputInfoPtr 
 				if (strcmp(fsource, psource))
 					match = 1;
 			}
-			free(fsource);
 			free(psource);
 		}
 	}
+	free(fsource);
+
 	if (match)
 		xf86Msg(X_WARNING, "%s: device file already in use by %s. "
 			"Ignoring.\n", pInfo->name, pDevices->name);
@@ -205,6 +206,10 @@ int wcmDeviceTypeKeys(InputInfoPtr pInfo
 		case 0x314: /* Intuos Pro S */
 		case 0x315: /* Intuos Pro M */
 		case 0x317: /* Intuos Pro L */
+		case 0x33B: /* Intuos Draw small */
+		case 0x33C: /* Intuos Art/Photo/Comic small */
+		case 0x33D: /* Intuos Draw medium */
+		case 0x33E: /* Intuos Art medium */
 		case 0x26:  /* I5 */
 		case 0x27:  /* I5 */
 		case 0x28:  /* I5 */
@@ -623,8 +628,10 @@ int wcmNeedAutoHotplug(InputInfoPtr pInf
 
 	if (!source) /* xorg.conf device, don't auto-pick type */
 		goto out;
-
-	if (source && strcmp(source, "server/hal") && strcmp(source, "server/udev"))
+	if (strcmp(source, "server/hal") &&
+	    strcmp(source, "server/udev") &&
+	    strcmp(source, "server/devd") &&
+	    strcmp(source, "server/wscons"))
 		goto out;
 
 	/* no type specified, so we need to pick the first one applicable

--- src/wcmValidateDevice.c.orig	2018-02-13 17:35:29 UTC
+++ src/wcmValidateDevice.c
@@ -34,6 +34,7 @@ static Bool wcmCheckSource(InputInfoPtr pInfo, dev_t m
 {
 	int match = 0;
 	InputInfoPtr pDevices = xf86FirstLocalDevice();
+	char* fsource = xf86CheckStrOption(pInfo->options, "_source", "");
 
 	for (; !match && pDevices != NULL; pDevices = pDevices->next)
 	{
@@ -51,7 +52,6 @@ static Bool wcmCheckSource(InputInfoPtr pInfo, dev_t m
 		if (pInfo != pDevices)
 		{
 			WacomCommonPtr pCommon = ((WacomDevicePtr)pDevices->private)->common;
-			char* fsource = xf86CheckStrOption(pInfo->options, "_source", "");
 			char* psource = xf86CheckStrOption(pDevices->options, "_source", "");
 
 			if (pCommon->min_maj &&
@@ -62,10 +62,11 @@ static Bool wcmCheckSource(InputInfoPtr pInfo, dev_t m
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
@@ -123,7 +124,7 @@ ret:
 static struct
 {
 	const char* type;
-	__u16 tool[3]; /* tool array is terminated by 0 */
+	uint16_t tool[3]; /* tool array is terminated by 0 */
 } wcmType [] =
 {
 	{ "stylus", { BTN_TOOL_PEN,       0                  } },
@@ -212,6 +213,10 @@ int wcmDeviceTypeKeys(InputInfoPtr pInfo)
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
@@ -659,8 +664,10 @@ int wcmNeedAutoHotplug(InputInfoPtr pInfo, char **type
 
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

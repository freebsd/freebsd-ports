# Finish converting AddEnabledDefice to xf86AddEnabledDevice
# Correct a couple strings that should be const
# Remove use of obsolete xf86XInputSetScreen
#
--- src/xf86PM.c.orig	2011-06-28 00:37:48 UTC
+++ src/xf86PM.c
@@ -61,7 +61,7 @@
  * Be sure to set vmin appropriately for your device's protocol. You want to
  * read a full packet before returning
  */
-static char *default_options[] =
+static const char *default_options[] =
 {
 	/*	"Device", "/dev/ttyS1",*/
 	"BaudRate", "19200",
@@ -258,7 +258,7 @@ DMC9000_ProcessDeviceOn(PenMountPrivateP
 	priv->lex_mode = PenMount_byte0;
 	
 	xf86FlushInput(pInfo->fd);
-	AddEnabledDevice (pInfo->fd);
+	xf86AddEnabledDevice (pInfo);
 	dev->public.on = TRUE;
 	return (Success);
 }
@@ -268,7 +268,7 @@ ProcessDeviceClose(PenMountPrivatePtr pr
 {
 	if (pInfo->fd != -1)
 		{ 
-			RemoveEnabledDevice (pInfo->fd);
+			xf86RemoveEnabledDevice (pInfo);
 			if (priv->buffer)
 				{
 					XisbFree(priv->buffer);
@@ -418,7 +418,7 @@ static int
 PenMountPreInit(InputDriverPtr drv, InputInfoPtr pInfo, int flags)
 {
 	PenMountPrivatePtr priv = calloc (1, sizeof (PenMountPrivateRec));
-	char *s;
+	const char *s;
 
 	if (!priv)
 		return BadAlloc;
@@ -603,7 +603,7 @@ DeviceControl (DeviceIntPtr dev, int mod
 		priv->lex_mode = PenMount_byte0;
 		
 		xf86FlushInput(pInfo->fd);
-		AddEnabledDevice (pInfo->fd);
+		xf86AddEnabledDevice (pInfo);
 		dev->public.on = TRUE;
 		return (Success);
 		
@@ -696,7 +696,7 @@ ReadInput (InputInfoPtr pInfo)
 					   priv->max_y);
                 }        		
 
-		xf86XInputSetScreen (pInfo, priv->screen_num, x, y);
+		//xf86XInputSetScreen (pInfo, priv->screen_num, x, y);
 
 		if ((priv->proximity == FALSE) && (priv->packet[0] & 0x01))
 		{
@@ -796,7 +796,7 @@ DMC9000_ReadInput (InputInfoPtr pInfo)
                 }
         		
 
-		xf86XInputSetScreen (pInfo, priv->screen_num, x, y);
+		//xf86XInputSetScreen (pInfo, priv->screen_num, x, y);
 
 		if ((priv->proximity == FALSE) && (priv->packet[0] & 0x01))
 		{

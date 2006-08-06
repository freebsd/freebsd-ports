--- wmclock.c.orig	Tue Mar  7 23:31:33 2000
+++ wmclock.c	
@@ -470,11 +470,11 @@
    XCopyArea(dpy, led.pixmap, visible.pixmap, normalGC,
 	     digitXOffset , digitYOffset, LED_NUM_WIDTH, LED_NUM_HEIGHT,
 	     xPos[DIGIT_1_X_POS], yPos[DIGIT_Y_POS]);
-   digitXOffset = LED_NUM_WIDTH * (year % 1000);
+   digitXOffset = LED_NUM_WIDTH * ((year / 100) % 10);
    XCopyArea(dpy, led.pixmap, visible.pixmap, normalGC,
 	     digitXOffset , digitYOffset, LED_NUM_WIDTH, LED_NUM_HEIGHT,
 	     xPos[DIGIT_2_X_POS], yPos[DIGIT_Y_POS]);
-   digitXOffset = LED_NUM_WIDTH * (year % 100);
+   digitXOffset = LED_NUM_WIDTH * ((year / 10) % 10);
    XCopyArea(dpy, led.pixmap, visible.pixmap, normalGC,
 	     digitXOffset , digitYOffset, LED_NUM_WIDTH, LED_NUM_HEIGHT,
 	     xPos[DIGIT_3_X_POS], yPos[DIGIT_Y_POS]);

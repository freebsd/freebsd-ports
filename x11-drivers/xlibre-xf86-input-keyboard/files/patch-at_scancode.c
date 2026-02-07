--- src/at_scancode.c.orig	Sun Jul  3 09:01:35 2005
+++ src/at_scancode.c	Sat Oct  7 21:27:29 2006
@@ -84,6 +84,10 @@
        case KEY_Prefix0:
           pKbd->scanPrefix = 0;
           switch (*scanCode) {
+            case 0x1e:            *scanCode = KEY_AudioRaise;break;
+            case 0x1f:            *scanCode = KEY_AudioLower;break;
+            case 0x20:            *scanCode = KEY_Power;     break;
+            case 0x25:            *scanCode = KEY_Mute;      break;
             case KEY_KP_7:        *scanCode = KEY_Home;      break;  /* curs home */
             case KEY_KP_8:        *scanCode = KEY_Up;        break;  /* curs up */
             case KEY_KP_9:        *scanCode = KEY_PgUp;      break;  /* curs pgup */
@@ -103,6 +107,17 @@
             case 0x5b:            *scanCode = KEY_LMeta;     break;
             case 0x5c:            *scanCode = KEY_RMeta;     break;
             case 0x5d:            *scanCode = KEY_Menu;      break;
+            case 0x5e:            *scanCode = KEY_L1;        break;  /* stop */
+            case 0x5f:            *scanCode = KEY_L2;        break;  /* again */
+            case 0x60:            *scanCode = KEY_L3;        break;  /* props */
+            case 0x61:            *scanCode = KEY_L4;        break;  /* undo */
+            case 0x62:            *scanCode = KEY_L5;        break;  /* front */
+            case 0x63:            *scanCode = KEY_L6;        break;  /* copy */
+            case 0x64:            *scanCode = KEY_L7;        break;  /* open */
+            case 0x65:            *scanCode = KEY_L8;        break;  /* paste */
+            case 0x66:            *scanCode = KEY_L9;        break;  /* find */
+            case 0x67:            *scanCode = KEY_L10;       break;  /* cut */
+            case 0x68:            *scanCode = KEY_Help;      break;
             case KEY_F3:          *scanCode = KEY_F13;       break;
             case KEY_F4:          *scanCode = KEY_F14;       break;
             case KEY_F5:          *scanCode = KEY_F15;       break;

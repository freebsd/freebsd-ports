--- input.c.orig	Mon Aug 21 08:47:47 2000
+++ input.c	Sat Feb 10 05:32:41 2001
@@ -155,7 +155,40 @@
 		      unparseputc (033, pty);  /* escape */
 		}
 		while (nbytes-- > 0)
+#ifndef NO_VIETNAMESE
+		{
+#include <vnkeys.h>
+			unsigned char       outchars[5];
+			register int        i;
+			int                 nchars;
+			extern Vk_Fsm       vn_keyboard_id;
+			extern Boolean      vn_filter_keyboard;
+
+			if (!vn_filter_keyboard) { /* don't filter */
+				unparseputc(*string++, pty);
+			} else {
+
+				Vk_State        state;
+				static Vk_State lastState;
+
+				/* feed in the keypresses */
+				state = vk_step(vn_keyboard_id, *string++, outchars, &nchars);
+				if (lastState != state) {
+					lastState = state;
+					_Set_Vn_Title(state);
+				}
+
+				/* send out the Vietnamese translation */
+				for (i = 0; i < nchars; i++) {
+					unparseputc(outchars[i], pty);
+				}
+			}
+		}
+#else /* NO_VIETNAMESE */
+		{
 			unparseputc(*string++, pty);
+		}
+#endif /* NO_VIETNAMESE */
 		key = TRUE;
 	}
 	if(key && !screen->TekEmu)
@@ -165,6 +198,47 @@
 #endif
 	return;
 }
+
+#ifndef NO_VIETNAMESE
+_Set_Vn_Title(state)
+    int               state;
+{
+    int               nochange = 0;
+    char      title[80], icon[80];
+    extern Boolean    vn_filter_keyboard;
+
+    strcpy(title, "vnterm-");
+    strcpy(icon, title);
+    if (!vn_filter_keyboard){
+      strcat(title, "No Filtering");
+      strcat(icon, "off");
+    } else {
+      switch(state) {
+      case VK_ST_VIETNAMESE:
+          strcat(title, "Vietnamese");
+          strcat(icon, "V");
+          break;
+      case VK_ST_ENGLISH:
+          strcat(title, "English");
+          strcat(icon, "E");
+          break;
+      case VK_ST_LITERAL:
+          strcat(title, "Literal");
+          strcat(icon, "L");
+          break;
+      default:
+          nochange = 1;
+          break;
+      }
+    }
+
+    if (!nochange) {
+      Changetitle(title);
+      Changename(icon);
+    }
+}
+#endif /* NO_VIETNAMESE */
+
 
 StringInput (screen, string, nbytes)
     register TScreen	*screen;

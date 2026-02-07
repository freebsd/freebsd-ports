--- mixedlist.c_old	2021-01-03 16:01:52.851092000 +0300
+++ mixedlist.c	2021-01-03 16:06:04.266150000 +0300
@@ -652,12 +652,12 @@
 						break;
 					case DLGK_ITEM_PREV:
 						i = choice - 1;
+						if (choice == 0 && scrollamt == 0)
+							continue;
 						if (items[scrollamt + i].type == ITEM_SEPARATOR && (scrollamt + i) == 0)
 							i++;
 						else if (items[scrollamt + i].type == ITEM_SEPARATOR)
 							i--;
-						if (choice == 0 && scrollamt == 0)
-							continue;
 						break;
 					case DLGK_ITEM_NEXT:
 						i = choice + 1;

--- term.c.orig	Sun Jun  2 22:40:30 2002
+++ term.c	Wed Aug 11 22:22:07 2004
@@ -2164,6 +2164,7 @@
 									ch = 'Û';
 									break;
 								default:
+									;
 							}
 							deadkey=0;
 							break;
@@ -2207,6 +2208,7 @@
 									ch = 'Ü';
 									break;
 								default:
+									;
 							}
 							deadkey=0;
 							break;
@@ -2587,6 +2589,7 @@
 										ch = 'Û';
 										break;
 									default:
+										;
 								}
 								deadkey=0;
 								break;
@@ -2630,6 +2633,7 @@
 										ch = 'Ü';
 										break;
 									default:
+										;
 								}
 								deadkey=0;
 								break;

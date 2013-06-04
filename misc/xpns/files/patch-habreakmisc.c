--- habreakmisc.c.orig
+++ habreakmisc.c
@@ -52,7 +52,7 @@ void HaBreakInit()
 ** RETURN: 	
 ** ANMERK: 	
 *************************************************************************/
-static HaBreakMark( MarkOn)
+static void HaBreakMark( MarkOn)
   BOOLEAN 	MarkOn;
 {
   OBJECT	*e;

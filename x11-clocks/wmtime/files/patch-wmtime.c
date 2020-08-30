--- wmtime.c.orig	1998-05-19 21:04:53 UTC
+++ wmtime.c
@@ -89,7 +89,7 @@
 char	*ProgName;
 int		digital = 0;
 char	day_of_week[7][3] = { "SU", "MO", "TU", "WE", "TH", "FR", "SA" };
-char	mon_of_year[12][4] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOW", "DEC" };
+char	mon_of_year[12][4] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
 
 /* functions */
 void usage(void);
@@ -166,6 +166,7 @@ void get_lang(){
 char		*left_action = NULL;
 char		*right_action = NULL;
 char		*middle_action = NULL;
+Display		*display;
 
 void DrawTime(int, int, int);
 void DrawWijzer(int, int, int);

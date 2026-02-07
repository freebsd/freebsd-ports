--- wmBinClock.c.orig	2015-12-06 01:59:53 UTC
+++ wmBinClock.c
@@ -58,8 +58,9 @@ int GotFirstClick1, GotDoubleClick1;
 int GotFirstClick2, GotDoubleClick2;
 int GotFirstClick3, GotDoubleClick3;
 int DblClkDelay;
+extern Display		*display;
 
-void IntToBinary(int x, int *str[]);
+void IntToBinary(int x, int *str);
 void PrintHelp(char err[]);
 
 int main(int argc, char *argv[])
@@ -660,7 +661,7 @@ int main(int argc, char *argv[])
 	    }
 
 	    tmp_hour = tmworld->tm_hour;
-	    IntToBinary(tmp_hour, &tmp_str);
+	    IntToBinary(tmp_hour, tmp_str);
 
 	    for (s = 0; s < 6; s++)
 	    {
@@ -671,7 +672,7 @@ int main(int argc, char *argv[])
 	    }
 
 	    tmp_minute = tmworld->tm_min;
-	    IntToBinary(tmp_minute, &tmp_str);
+	    IntToBinary(tmp_minute, tmp_str);
 	    for (s = 0; s < 6; s++)
 	    {
 		if (tmp_str[s] == 1)
@@ -681,7 +682,7 @@ int main(int argc, char *argv[])
 	    }
 	
 	    tmp_second = tmworld->tm_sec;
-	    IntToBinary(tmp_second, &tmp_str);
+	    IntToBinary(tmp_second, tmp_str);
 	    
 	    for (s = 0; s < 6; s++)
 	    {
@@ -692,7 +693,7 @@ int main(int argc, char *argv[])
 	    }
 	    
 	    tmp_day = tmworld->tm_mday;
-	    IntToBinary(tmp_day, &tmp_str);
+	    IntToBinary(tmp_day, tmp_str);
 	    
 	    for (s = 0; s < 6; s++)
 	    {
@@ -703,7 +704,7 @@ int main(int argc, char *argv[])
 	    }
 
 	    tmp_month = tmworld->tm_mon + 1;
-	    IntToBinary(tmp_month, &tmp_str);
+	    IntToBinary(tmp_month, tmp_str);
 	    
 	    for (s = 0; s < 6; s++)
 	    {
@@ -773,7 +774,7 @@ int main(int argc, char *argv[])
 	usleep(DELAY);
     }
 }
-void IntToBinary(int x, int *str[])
+void IntToBinary(int x, int *str)
 {
     int i = 0;
     int counter = 0;
@@ -884,7 +885,7 @@ void PrintHelp(char err[])
 	strcpy(str,"Error in ");
 	strcat(str,err);
 	strcat(str,".\n\n");
-	printf(str);
+	printf("%s", str);
     }
 
     printf("Usage: wmBinClock [OPTIONS]\n\n");

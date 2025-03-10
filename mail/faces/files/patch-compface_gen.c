--- compface/gen.c.orig
+++ compface/gen.c
@@ -18,62 +18,65 @@
 
 #define GEN(g) F[h] ^= G.g[k]; break
 
-static void Gen(char *);
+static void Gen P((char *)) ;
 
 static void
-Gen(char *f)
+Gen(f)
+register char *f;
 {
-    int m, l, k, j, i, h;
+	register int m, l, k, j, i, h;
 
-    for (j = 0; j < HEIGHT;  j++) {
-        for (i = 0; i < WIDTH;  i++) {
+	for (j = 0; j < HEIGHT;  j++)
+	{
+		for (i = 0; i < WIDTH;  i++)
+		{
             h = i + j * WIDTH;
             k = 0;
-            for (l = i - 2; l <= i + 2; l++) {
-                for (m = j - 2; m <= j; m++) {
-                    if ((l >= i) && (m == j)) {
+			for (l = i - 2; l <= i + 2; l++)
+				for (m = j - 2; m <= j; m++)
+				{
+					if ((l >= i) && (m == j))
                         continue;
-                    }
-                    if ((l > 0) && (l <= WIDTH) && (m > 0)) {
+					if ((l > 0) && (l <= WIDTH) && (m > 0))
                         k = *(f + l + m * WIDTH) ? k * 2 + 1 : k * 2;
                     }
-                }
-            }
-            switch (i) {
+			switch (i)
+			{
                 case 1 :
-                    switch (j) {
+					switch (j)
+					{
                         case 1 : GEN(g_22);
                         case 2 : GEN(g_21);
                         default : GEN(g_20);
                     }
                     break;
-
                 case 2 :
-                    switch (j) {
+					switch (j)
+					{
                         case 1 : GEN(g_12);
                         case 2 : GEN(g_11);
                         default : GEN(g_10);
                     }
                     break;
-
                 case WIDTH - 1 :
-                    switch (j) {
+					switch (j)
+					{
                         case 1 : GEN(g_42);
                         case 2 : GEN(g_41);
                         default : GEN(g_40);
                     }
                     break;
-
                 case WIDTH :
-                    switch (j) {
+					switch (j)
+					{
                         case 1 : GEN(g_32);
                         case 2 : GEN(g_31);
                         default : GEN(g_30);
                     }
                     break;
-
                 default :
-                    switch (j) {
+					switch (j)
+					{
                         case 1 : GEN(g_02);
                         case 2 : GEN(g_01);
                         default : GEN(g_00);
@@ -84,26 +87,25 @@
     }
 }
 
-
 void
 GenFace()
 {
     static char new[PIXELS];
-    char *f1, *f2;
-    int i;
+	register char *f1;
+	register char *f2;
+	register int i;
 
     f1 = new;
     f2 = F;
     i = PIXELS;
-    while (i-- > 0) {
+	while (i-- > 0)
         *(f1++) = *(f2++);
-    }
     Gen(new);
 }
 
-
 void
 UnGenFace()
 {
     Gen(F);
 }
+

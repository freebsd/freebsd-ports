
$FreeBSD$

--- source/secscanf.c	2002/10/18 09:04:10	1.1
+++ source/secscanf.c	2002/10/18 09:12:07
@@ -45,6 +45,21 @@
 static int	process_number(union scan_value *vp, const char **sp, char fmt);
 static int	process_char_class(const char **, const char **, int);
 
+#if __FreeBSD__
+static char *
+strndup(const char *src, size_t size)
+{
+	char *dst;
+
+	dst = malloc(size + 1);
+	if (dst == NULL)
+		return (NULL);
+	dst[size] = '\0';
+	strncpy(dst, src, size);
+	return (dst);
+}
+#endif
+
 static inline int
 set_conv_type(int *type, int new_type)
 {
@@ -347,7 +362,7 @@
 	case 'g':
 	case 'e':
 	case 'E':
-		vp->v_double = strtold(s, (char **) sp);
+		vp->v_double = strtod(s, (char **) sp);
 		break;
 	default:
 		return 0;

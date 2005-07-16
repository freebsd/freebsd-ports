--- courier/submit.C.orig	Fri Apr 22 21:38:00 2005
+++ courier/submit.C	Fri Apr 22 21:38:00 2005
@@ -531,6 +531,7 @@
 	(*hdrOut) += str;
 	(*hdrOut) += " (";
 	(*hdrOut) += errmsg_buf;
+/*
 	(*hdrOut) += ")\n  SPF=";
 	(*hdrOut) += checkname;
 	(*hdrOut) += ";\n";
@@ -550,6 +551,43 @@
 		(*hdrOut) += v ? v:strerror(errno);
 		(*hdrOut) += ";\n";
 	}
+*/
+	(*hdrOut) += ")\n  ";
+	(*hdrOut) += checkname;
+	{
+		char *v=strdup(values[0] ? values[0] : "");
+
+		for (q=v; q && *q; q++)
+			if (*q < ' ' || *q >= 127)
+				*q='?';
+			else if (*q == ';')
+				*q=' ';
+		(*hdrOut) += " ";
+		(*hdrOut) += v ? v:strerror(errno);
+	}
+	{
+		char *v=strdup(values[2] ? values[2] : "");
+
+		for (q=v; q && *q; q++)
+			if (*q < ' ' || *q >= 127)
+				*q='?';
+			else if (*q == ';')
+				*q=' ';
+		(*hdrOut) += " (";
+		(*hdrOut) += v ? v:strerror(errno);
+	}
+	{
+		char *v=strdup(values[1] ? values[1] : "");
+
+		for (q=v; q && *q; q++)
+			if (*q < ' ' || *q >= 127)
+				*q='?';
+			else if (*q == ';')
+				*q=' ';
+		(*hdrOut) += " [";
+		(*hdrOut) += v ? v:strerror(errno);
+	}
+	(*hdrOut) += "]);\n";
 	return str;
 }
 

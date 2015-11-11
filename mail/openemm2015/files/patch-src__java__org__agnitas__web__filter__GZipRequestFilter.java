--- src/java/org/agnitas/web/filter/GZipRequestFilter.java.orig	2015-10-24 14:59:58 UTC
+++ src/java/org/agnitas/web/filter/GZipRequestFilter.java
@@ -39,6 +39,8 @@ import javax.servlet.ServletInputStream;
 import javax.servlet.ServletOutputStream;
 import javax.servlet.ServletRequest;
 import javax.servlet.ServletResponse;
+import javax.servlet.WriteListener;
+import javax.servlet.ReadListener;
 import javax.servlet.http.HttpServletRequest;
 import javax.servlet.http.HttpServletRequestWrapper;
 import javax.servlet.http.HttpServletResponse;
@@ -177,6 +179,16 @@ public class GZipRequestFilter implement
                 throws IOException {
         	this.gzipOutputStream.write(bytes, offset, length);
         }
+
+	@Override
+	public void setWriteListener(WriteListener writeListener){
+
+	}
+
+	@Override
+	public boolean isReady(){
+		return true;
+	}
    }
 
     private class GZIPServletRequestWrapper extends HttpServletRequestWrapper{
@@ -207,5 +219,26 @@ public class GZipRequestFilter implement
         public int read() throws IOException {
             return this.input.read();
         }
+	
+	@Override
+	public void setReadListener(ReadListener readListener){
+	}
+
+	@Override
+	public boolean isReady(){
+		return true;  
+	}
+
+	@Override
+	public boolean isFinished() {
+
+		int count = -1;
+
+		try{
+			count = this.input.available();
+		} catch (IOException ioe){}
+
+		return count <= 0; 
+	}
     }
 }

--- gtk_ui.c.orig	Tue Feb  4 17:51:19 2003
+++ gtk_ui.c	Tue Feb  4 17:51:37 2003
@@ -24,7 +24,7 @@
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
-$Id: //depot/fish/gtk_ui.c#28 $
+$Id: //depot/fish/gtk_ui.c#29 $
 
 */
 
@@ -33,6 +33,10 @@
 #include <string.h>
 #include <fcntl.h>
 
+#include <sys/types.h>
+#include <sys/uio.h>
+#include <unistd.h>
+
 #include <time.h>
 extern char *tzname[2];
 
@@ -66,6 +70,8 @@
 void add_yes_pressed(GtkWidget *, gpointer);
 void add_no_pressed(GtkWidget *, gpointer);
 
+void save_geometry(void);
+
 /* Some defines here */
 #define IS_DIRTY 1
 #define NOT_DIRTY 0
@@ -139,7 +145,10 @@
 	GtkWidget *window;
 	GtkWidget *myviewport1;
 	GtkWidget *myviewport2;
-	
+
+	/* Window geometry */
+	int oldsize[2];
+		
 /* I know this code looks chaotic at first sight, but it seems to work :-) */
 int
 create_gtk_ui(RC_NODE *rc_knobs,int num_knobs,RC_NODE *rc_strings,int num_str)
@@ -202,6 +211,10 @@
 		
 	int i;
 
+	char *homedir;
+	char temp[255];
+	int fd;
+	
 	commit_win_up=FALSE;
 	add_win_up=FALSE;
 	about_win_up=FALSE;
@@ -218,6 +231,27 @@
 	gtk_window_set_title(GTK_WINDOW(window),"The Fish");
 
 
+	/* Set the size */
+	
+	homedir=getenv("HOME");
+	if(homedir!=NULL) {
+	
+		snprintf(temp,255,"%s/%s",homedir,".thefishrc");
+		fd=open(temp,O_RDONLY,0);
+		if(fd!=-1) {
+		read(fd,&oldsize[0],sizeof(oldsize));
+		close(fd);
+		} else  {
+		
+		oldsize[0]=400;
+		oldsize[1]=480;
+		
+		}
+		
+	}	
+
+	gtk_window_set_default_size(GTK_WINDOW(window),oldsize[0],oldsize[1]);
+	 
 	/* Set the icon */
 	icon16_pixbuf=gdk_pixbuf_new_from_xpm_data((const char **)icon16);
 	icon32_pixbuf=gdk_pixbuf_new_from_xpm_data((const char **)icon32);
@@ -561,6 +595,7 @@
 void 
 destroy( GtkWidget *widget, gpointer data)
 {
+	save_geometry();
     gtk_main_quit();
 }
 
@@ -583,10 +618,15 @@
 		result=gtk_dialog_run (GTK_DIALOG (dialog));
 		gtk_widget_destroy (dialog);	
 
-		if(result==GTK_RESPONSE_YES) gtk_main_quit();
+		if(result==GTK_RESPONSE_YES) {
+		
+			save_geometry();
+			gtk_main_quit();
+		}
 	
-		} else {
+	} else {
 	
+		save_geometry();
     	gtk_main_quit();
 	
 	}
@@ -1167,4 +1207,29 @@
 	gtk_widget_destroy(add_window);
 
 	add_win_up=FALSE;
+}
+
+void
+save_geometry(void)
+{
+
+	int newsize[2];
+	char *homedir;
+	char temp[255];
+	int fd;
+	
+	gtk_window_get_size(GTK_WINDOW(window),&newsize[0],&newsize[1]);
+	
+	if(oldsize[0]!=newsize[0] || oldsize[1]!=newsize[1]) {
+	
+		homedir=getenv("HOME");
+		if(homedir==NULL) return;
+		snprintf(temp,255,"%s/%s",homedir,".thefishrc");
+		fd=open(temp,O_WRONLY|O_CREAT|O_TRUNC,0666);
+		if(fd==-1) return;
+		write(fd,&newsize[0],sizeof(newsize));
+		close(fd);
+		return;
+		
+	}
 }

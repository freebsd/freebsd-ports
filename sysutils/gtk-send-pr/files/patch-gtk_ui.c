--- gtk_ui.c.old	Sun Nov  7 17:44:39 2004
+++ gtk_ui.c	Mon Nov  8 21:36:26 2004
@@ -21,7 +21,7 @@
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
-  $Id: //depot/gtk-send-pr/gtk_ui.c#21 $
+  $Id: //depot/gtk-send-pr/gtk_ui.c#22 $
 
 */
 
@@ -514,8 +514,11 @@
   gtk_container_set_border_width(GTK_CONTAINER(scrolled_window1), 10);
   gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window1),
 				 GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
-  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window1)
-					, system_view1);
+  //  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window1)
+  //				, system_view1);
+
+  gtk_container_add(GTK_CONTAINER(scrolled_window1)
+		    , system_view1);
 
   gtk_container_add(GTK_CONTAINER(system_frame1), system_entry1);
   gtk_container_add(GTK_CONTAINER(system_frame2), scrolled_window1);
@@ -534,8 +537,11 @@
   gtk_container_set_border_width(GTK_CONTAINER(scrolled_window2), 10);
   gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window2),
 				 GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
-  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window2)
-					, details_view1);
+  //  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window2)
+  //				, details_view1);
+
+  gtk_container_add(GTK_CONTAINER(scrolled_window2)
+		    , details_view1);
 
   details_frame2 = gtk_frame_new(" How-To-Repeat ");
 
@@ -546,8 +552,11 @@
   gtk_container_set_border_width(GTK_CONTAINER(scrolled_window3), 10);
   gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window3),
 				 GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
-  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window3)
-					, details_view2);
+/*   gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window3) */
+/* 					, details_view2); */
+
+  gtk_container_add(GTK_CONTAINER(scrolled_window3)
+		    , details_view2);
 
   gtk_container_add(GTK_CONTAINER(details_frame1), scrolled_window2);
   gtk_container_add(GTK_CONTAINER(details_frame2), scrolled_window3);
@@ -601,8 +610,12 @@
   gtk_container_set_border_width(GTK_CONTAINER(scrolled_window4), 10);
   gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window4),
 				 GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
-  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window4)
-					, fix_view);
+
+/*   gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window4) */
+/* 					, fix_view); */
+
+  gtk_container_add(GTK_CONTAINER(scrolled_window4)
+		    , fix_view);
 
   gtk_container_add(GTK_CONTAINER(fix_frame), scrolled_window4);
 

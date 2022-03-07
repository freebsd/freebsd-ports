--- lib/functions.php.orig	2021-12-12 02:35:51 UTC
+++ lib/functions.php
@@ -928,7 +928,7 @@ function get_cached_item($index,$item,$subitem='null')
  *
  * Returns true on success of false on failure.
  */
-function set_cached_item($index,$item,$subitem='null',$data) {
+function set_cached_item($index,$data,$item,$subitem='null') {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
@@ -2032,8 +2032,8 @@ function ldap_error_msg($msg,$errnum) {
  *
  * Usage Examples:
  *  <code>
- *   draw_jpeg_photo(0,'cn=Bob,ou=People,dc=example,dc=com',"jpegPhoto",0,true,array('img_opts'=>"border: 1px; width: 150px"));
- *   draw_jpeg_photo(1,'cn=Fred,ou=People,dc=example,dc=com',null,1);
+ *   draw_jpeg_photo(0,'cn=Bob,ou=People,dc=example,dc=com',0,"jpegPhoto",true,array('img_opts'=>"border: 1px; width: 150px"));
+ *   draw_jpeg_photo(1,'cn=Fred,ou=People,dc=example,dc=com',1,null);
  *  </code>
  *
  * @param object The Server to get the image from.
@@ -2046,7 +2046,7 @@ function ldap_error_msg($msg,$errnum) {
  * @param array Specifies optional image and CSS style attributes for the table tag. Supported keys are
  *                fixed_width, fixed_height, img_opts.
  */
-function draw_jpeg_photo($server,$dn,$attr_name='jpegphoto',$index,$draw_delete_buttons=false,$options=array()) {
+function draw_jpeg_photo($server,$dn,$index,$attr_name='jpegphoto',$draw_delete_buttons=false,$options=array()) {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 

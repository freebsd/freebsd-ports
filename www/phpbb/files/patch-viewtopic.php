--- viewtopic.php.orig	Mon Jul  7 12:23:41 2003
+++ viewtopic.php	Mon Jul  7 12:25:01 2003
@@ -29,6 +29,7 @@
 //
 // Start initial var setup
 //
+$topic_id = $post_id = false;
 if ( isset($HTTP_GET_VARS[POST_TOPIC_URL]) )
 {
 	$topic_id = intval($HTTP_GET_VARS[POST_TOPIC_URL]);
@@ -134,11 +135,11 @@
 // also allows for direct linking to a post (and the calculation of which
 // page the post is on and the correct display of viewtopic)
 //
-$join_sql_table = ( !isset($post_id) ) ? '' : ", " . POSTS_TABLE . " p, " . POSTS_TABLE . " p2 ";
-$join_sql = ( !isset($post_id) ) ? "t.topic_id = $topic_id" : "p.post_id = $post_id AND t.topic_id = p.topic_id AND p2.topic_id = p.topic_id AND p2.post_id <= $post_id";
-$count_sql = ( !isset($post_id) ) ? '' : ", COUNT(p2.post_id) AS prev_posts";
+$join_sql_table = ( empty($post_id) ) ? '' : ", " . POSTS_TABLE . " p, " . POSTS_TABLE . " p2 ";
+$join_sql = ( empty($post_id) ) ? "t.topic_id = $topic_id" : "p.post_id = $post_id AND t.topic_id = p.topic_id AND p2.topic_id = p.topic_id AND p2.post_id <= $post_id";
+$count_sql = ( empty($post_id) ) ? '' : ", COUNT(p2.post_id) AS prev_posts";
 
-$order_sql = ( !isset($post_id) ) ? '' : "GROUP BY p.post_id, t.topic_id, t.topic_title, t.topic_status, t.topic_replies, t.topic_time, t.topic_type, t.topic_vote, t.topic_last_post_id, f.forum_name, f.forum_status, f.forum_id, f.auth_view, f.auth_read, f.auth_post, f.auth_reply, f.auth_edit, f.auth_delete, f.auth_sticky, f.auth_announce, f.auth_pollcreate, f.auth_vote, f.auth_attachments ORDER BY p.post_id ASC";
+$order_sql = ( empty($post_id) ) ? '' : "GROUP BY p.post_id, t.topic_id, t.topic_title, t.topic_status, t.topic_replies, t.topic_time, t.topic_type, t.topic_vote, t.topic_last_post_id, f.forum_name, f.forum_status, f.forum_id, f.auth_view, f.auth_read, f.auth_post, f.auth_reply, f.auth_edit, f.auth_delete, f.auth_sticky, f.auth_announce, f.auth_pollcreate, f.auth_vote, f.auth_attachments ORDER BY p.post_id ASC";
 
 $sql = "SELECT t.topic_id, t.topic_title, t.topic_status, t.topic_replies, t.topic_time, t.topic_type, t.topic_vote, t.topic_last_post_id, f.forum_name, f.forum_status, f.forum_id, f.auth_view, f.auth_read, f.auth_post, f.auth_reply, f.auth_edit, f.auth_delete, f.auth_sticky, f.auth_announce, f.auth_pollcreate, f.auth_vote, f.auth_attachments" . $count_sql . "
 	FROM " . TOPICS_TABLE . " t, " . FORUMS_TABLE . " f" . $join_sql_table . "


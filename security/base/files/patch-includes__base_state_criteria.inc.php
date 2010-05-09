--- ./includes/base_state_criteria.inc.php.orig	2010-03-05 16:06:18.000000000 +0100
+++ ./includes/base_state_criteria.inc.php	2010-04-11 23:52:13.000000000 +0200
@@ -252,7 +252,7 @@
    if ( isset($_POST['current_view']) ) $query_string .= "&amp;current_view=".$_POST['current_view'];
    if ( isset($_POST['submit']) ) $query_string .= "&amp;submit=".$_POST['submit'];
 
-   $query_string = ereg_replace("back=1&", "", CleanVariable($query_string, VAR_PERIOD | VAR_DIGIT | VAR_PUNC | VAR_LETTER));
+   $query_string = preg_replace("/back=1&/", "", CleanVariable($query_string, VAR_PERIOD | VAR_DIGIT | VAR_PUNC | VAR_LETTER));
 
    ++$_SESSION['back_list_cnt'];
    $_SESSION['back_list'][$_SESSION['back_list_cnt']] =  

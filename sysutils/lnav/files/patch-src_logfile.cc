--- src/logfile.cc.orig	2020-09-09 16:17:12 UTC
+++ src/logfile.cc
@@ -323,10 +323,13 @@ logfile::rebuild_result_t logfile::rebuild_index()
 
             this->lf_line_buffer.clear();
             if (!this->lf_index.empty()) {
-                off_t check_line_off = this->lf_index.back().get_offset();
+                auto last_line = this->lf_index.end();
+                --last_line;
+                off_t check_line_off = last_line->get_offset();
+                auto last_length = ssize_t(this->line_length(last_line, false));
 
                 auto read_result = this->lf_line_buffer.read_range({
-                    check_line_off, this->lf_index_size - check_line_off
+                    check_line_off, last_length
                 });
 
                 if (read_result.isErr()) {
@@ -553,7 +556,7 @@ filesystem::path logfile::get_path() const
 
 size_t logfile::line_length(logfile::iterator ll, bool include_continues)
 {
-    iterator next_line = ll;
+    auto next_line = ll;
     size_t retval;
 
     if (!include_continues && this->lf_next_line_cache) {
@@ -570,6 +573,9 @@ size_t logfile::line_length(logfile::iterator ll, bool
 
     if (next_line == this->end()) {
         retval = this->lf_index_size - ll->get_offset();
+        if (retval > line_buffer::MAX_LINE_BUFFER_SIZE) {
+            retval = line_buffer::MAX_LINE_BUFFER_SIZE;
+        }
         if (retval > 0 && !this->lf_partial_line) {
             retval -= 1;
         }

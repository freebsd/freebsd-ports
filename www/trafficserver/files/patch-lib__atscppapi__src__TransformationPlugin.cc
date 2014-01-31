--- ./lib/atscppapi/src/TransformationPlugin.cc.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./lib/atscppapi/src/TransformationPlugin.cc	2014-01-27 08:45:49.000000000 +0000
@@ -91,7 +91,7 @@
   TSVIO write_vio = TSVConnWriteVIOGet(contp);
   if (write_vio) {
     int64_t to_read = TSVIONTodoGet(write_vio);
-    LOG_DEBUG("Transformation contp=%p write_vio=%p, to_read=%ld", contp, write_vio, to_read);
+    LOG_DEBUG("Transformation contp=%p write_vio=%p, to_read=%lld", contp, write_vio, to_read);
 
     if (to_read > 0) {
       /*
@@ -99,11 +99,11 @@
        * the amount of data actually in the read buffer.
        **/
       int64_t avail = TSIOBufferReaderAvail(TSVIOReaderGet(write_vio));
-      LOG_DEBUG("Transformation contp=%p write_vio=%p, to_read=%ld, buffer reader avail=%ld", contp, write_vio, to_read, avail);
+      LOG_DEBUG("Transformation contp=%p write_vio=%p, to_read=%lld, buffer reader avail=%lld", contp, write_vio, to_read, avail);
 
       if (to_read > avail) {
         to_read = avail;
-        LOG_DEBUG("Transformation contp=%p write_vio=%p, to read > avail, fixing to_read to be equal to avail. to_read=%ld, buffer reader avail=%ld", contp, write_vio, to_read, avail);
+        LOG_DEBUG("Transformation contp=%p write_vio=%p, to read > avail, fixing to_read to be equal to avail. to_read=%lld, buffer reader avail=%lld", contp, write_vio, to_read, avail);
       }
 
       if (to_read > 0) {
@@ -122,7 +122,7 @@
         TSVIONDoneSet(write_vio, TSVIONDoneGet(write_vio) + to_read);
 
         std::string in_data = utils::internal::consumeFromTSIOBufferReader(input_reader);
-        LOG_DEBUG("Transformation contp=%p write_vio=%p consumed %ld bytes from bufferreader", contp, write_vio, in_data.length());
+        LOG_DEBUG("Transformation contp=%p write_vio=%p consumed %zu bytes from bufferreader", contp, write_vio, in_data.length());
 
         /* Clean up the buffer and reader */
         TSIOBufferReaderFree(input_reader);
@@ -232,7 +232,7 @@
 }
 
 size_t TransformationPlugin::produce(const std::string &data) {
-  LOG_DEBUG("TransformationPlugin=%p tshttptxn=%p producing output with length=%ld", this, state_->txn_, data.length());
+  LOG_DEBUG("TransformationPlugin=%p tshttptxn=%p producing output with length=%zu", this, state_->txn_, data.length());
   int64_t write_length = static_cast<int64_t>(data.length());
   if (!write_length) {
     return 0;
@@ -261,11 +261,11 @@
   // Finally we can copy this data into the output_buffer
   int64_t bytes_written = TSIOBufferWrite(state_->output_buffer_, data.c_str(), write_length);
   state_->bytes_written_ += bytes_written; // So we can set BytesDone on outputComplete().
-  LOG_DEBUG("TransformationPlugin=%p tshttptxn=%p write to TSIOBuffer %ld bytes total bytes written %ld", this, state_->txn_, bytes_written, state_->bytes_written_);
+  LOG_DEBUG("TransformationPlugin=%p tshttptxn=%p write to TSIOBuffer %lld bytes total bytes written %lld", this, state_->txn_, bytes_written, state_->bytes_written_);
 
   // Sanity Checks
   if (bytes_written != write_length) {
-    LOG_ERROR("TransformationPlugin=%p tshttptxn=%p bytes written < expected. bytes_written=%ld write_length=%ld", this, state_->txn_, bytes_written, write_length);
+    LOG_ERROR("TransformationPlugin=%p tshttptxn=%p bytes written < expected. bytes_written=%lld write_length=%lld", this, state_->txn_, bytes_written, write_length);
   }
 
   int connection_closed = TSVConnClosedGet(state_->vconn_);
@@ -282,7 +282,7 @@
 
 size_t TransformationPlugin::setOutputComplete() {
   int connection_closed = TSVConnClosedGet(state_->vconn_);
-  LOG_DEBUG("OutputComplete TransformationPlugin=%p tshttptxn=%p vconn=%p connection_closed=%d, total bytes written=%ld", this, state_->txn_, state_->vconn_, connection_closed,state_->bytes_written_);
+  LOG_DEBUG("OutputComplete TransformationPlugin=%p tshttptxn=%p vconn=%p connection_closed=%d, total bytes written=%lld", this, state_->txn_, state_->vconn_, connection_closed,state_->bytes_written_);
 
   if (!connection_closed && !state_->output_vio_) {
       LOG_DEBUG("TransformationPlugin=%p tshttptxn=%p output complete without writing any data, initiating write of 0 bytes.", this, state_->txn_);

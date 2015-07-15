--- lib/atscppapi/src/AsyncHttpFetch.cc.orig	2015-06-30 04:11:56 UTC
+++ lib/atscppapi/src/AsyncHttpFetch.cc
@@ -107,7 +107,7 @@ handleFetchEvents(TSCont cont, TSEvent e
           state->body_ = data_start; // data_start will now be pointing to body
           state->body_size_ = data_end - data_start;
           utils::internal::initResponse(state->response_, state->hdr_buf_, state->hdr_loc_);
-          LOG_DEBUG("Fetch result had a status code of %d with a body length of %ld", status, state->body_size_);
+          LOG_DEBUG("Fetch result had a status code of %d with a body length of %zu", status, state->body_size_);
         } else {
           LOG_ERROR("Unable to parse response; Request URL [%s]; transaction %p", state->request_->getUrl().getUrlString().c_str(),
                     txn);

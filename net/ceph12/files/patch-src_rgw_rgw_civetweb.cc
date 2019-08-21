*** src/rgw/rgw_civetweb.cc	Thu Apr 11 14:33:50 2019
--- src/rgw/rgw_civetweb.cc.new	Mon Aug 19 11:31:24 2019
***************
*** 89,95 ****
    }
  
    for (int i = 0; i < info->num_headers; i++) {
!     const struct mg_request_info::mg_header* header = &info->http_headers[i];
  
      if (header->name == nullptr || header->value==nullptr) {
        lderr(cct) << "client supplied malformatted headers" << dendl;
--- 89,95 ----
    }
  
    for (int i = 0; i < info->num_headers; i++) {
!     const auto header = &info->http_headers[i];
  
      if (header->name == nullptr || header->value==nullptr) {
        lderr(cct) << "client supplied malformatted headers" << dendl;
***************
*** 132,138 ****
    env.set("REQUEST_METHOD", info->request_method);
    env.set("HTTP_VERSION", info->http_version);
    env.set("REQUEST_URI", info->request_uri); // get the full uri, we anyway handle abs uris later
!   env.set("SCRIPT_URI", info->uri); /* FIXME */
    if (info->query_string) {
      env.set("QUERY_STRING", info->query_string);
    }
--- 132,138 ----
    env.set("REQUEST_METHOD", info->request_method);
    env.set("HTTP_VERSION", info->http_version);
    env.set("REQUEST_URI", info->request_uri); // get the full uri, we anyway handle abs uris later
!   env.set("SCRIPT_URI", info->local_uri); 
    if (info->query_string) {
      env.set("QUERY_STRING", info->query_string);
    }

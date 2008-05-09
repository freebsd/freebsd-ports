// -*- mode: cpp; mode: fold -*-
// Description								/*{{{*/// $Id: http.h,v 1.12 2002/04/18 05:09:38 jgg Exp $
// $Id: http.h,v 1.12 2002/04/18 05:09:38 jgg Exp $
/* ######################################################################

   HTTP Acquire Method - This is the HTTP aquire method for APT.

   ##################################################################### */
									/*}}}*/

#ifndef APT_HTTP_H
#define APT_HTTP_H

#define MAXLEN 360

#include <iostream>
#include <curl/curl.h>

using std::cout;
using std::endl;

class HttpsMethod;


class HttpsMethod : public pkgAcqMethod
{

   virtual bool Fetch(FetchItem *);
   static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);
   static int progress_callback(void *clientp, double dltotal, double dlnow, 
				double ultotal, double ulnow);
   void SetupProxy();
   CURL *curl;
   FetchResult Res;

   public:
   FileFd *File;
      
   HttpsMethod() : pkgAcqMethod("1.2",Pipeline | SendConfig) 
   {
      File = 0;
      curl = curl_easy_init();
   };
};

URI Proxy;

#endif

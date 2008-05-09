// -*- mode: cpp; mode: fold -*-
// Description								/*{{{*/
// $Id: http.cc,v 1.59 2004/05/08 19:42:35 mdz Exp $
/* ######################################################################

   HTTPS Acquire Method - This is the HTTPS aquire method for APT.
   
   It uses libcurl

   ##################################################################### */
									/*}}}*/
// Include Files							/*{{{*/
#include <apt-pkg/fileutl.h>
#include <apt-pkg/acquire-method.h>
#include <apt-pkg/error.h>
#include <apt-pkg/hashes.h>

#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <apti18n.h>
#include <sstream>

#include "config.h"
#include "https.h"

									/*}}}*/
using namespace std;

size_t 
HttpsMethod::write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
   HttpsMethod *me = (HttpsMethod *)userp;

   if(me->File->Write(buffer, size*nmemb) != true)
      return false;

   return size*nmemb;
}

int 
HttpsMethod::progress_callback(void *clientp, double dltotal, double dlnow, 
			      double ultotal, double ulnow)
{
   HttpsMethod *me = (HttpsMethod *)clientp;
   if(dltotal > 0 && me->Res.Size == 0) {
      me->Res.Size = (unsigned long)dltotal;
      me->URIStart(me->Res);
   }
   return 0;
}

void HttpsMethod::SetupProxy()
{
   URI ServerName = Queue->Uri;

   // Determine the proxy setting
   if (getenv("http_proxy") == 0)
   {
      string DefProxy = _config->Find("Acquire::http::Proxy");
      string SpecificProxy = _config->Find("Acquire::http::Proxy::" + ServerName.Host);
      if (SpecificProxy.empty() == false)
      {
	 if (SpecificProxy == "DIRECT")
	    Proxy = "";
	 else
	    Proxy = SpecificProxy;
      }   
      else
	 Proxy = DefProxy;
   }
   
   // Parse no_proxy, a , separated list of domains
   if (getenv("no_proxy") != 0)
   {
      if (CheckDomainList(ServerName.Host,getenv("no_proxy")) == true)
	 Proxy = "";
   }
   
   // Determine what host and port to use based on the proxy settings
   string Host;   
   if (Proxy.empty() == true || Proxy.Host.empty() == true)
   {
   }
   else
   {
      if (Proxy.Port != 0)
	 curl_easy_setopt(curl, CURLOPT_PROXYPORT, Proxy.Port);
      curl_easy_setopt(curl, CURLOPT_PROXY, Proxy.Host.c_str());
   }
}


// HttpsMethod::Fetch - Fetch an item					/*{{{*/
// ---------------------------------------------------------------------
/* This adds an item to the pipeline. We keep the pipeline at a fixed
   depth. */
bool HttpsMethod::Fetch(FetchItem *Itm)
{
   stringstream ss;
   struct stat SBuf;
   struct curl_slist *headers=NULL;  
   char curl_errorstr[CURL_ERROR_SIZE];
   long curl_responsecode;

   // TODO:
   //       - http::Timeout
   //       - http::Pipeline-Depth
   //       - error checking/reporting
   //       - more debug options? (CURLOPT_DEBUGFUNCTION?)

   curl_easy_reset(curl);
   SetupProxy();

   // callbacks
   curl_easy_setopt(curl, CURLOPT_URL, Itm->Uri.c_str());
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
   curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
   curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, this);
   curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
   curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
   curl_easy_setopt(curl, CURLOPT_FILETIME, true);

   // FIXME: https: offer various options of verification
   bool peer_verify = _config->FindB("Acquire::https::Verify-Peer", false);
   curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, peer_verify);

   // sslcert file
   string pem = _config->Find("Acquire::https::SslCert","");
   if(pem != "")
      curl_easy_setopt(curl, CURLOPT_SSLCERT, pem.c_str());
   
   // CA-Dir
   string certdir = _config->Find("Acquire::https::CaPath","");
   if(certdir != "")
      curl_easy_setopt(curl, CURLOPT_CAPATH, certdir.c_str());
   
   // Server-verify 
   int verify = _config->FindI("Acquire::https::Verify-Host",2);
   curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, verify);

   // cache-control
   if(_config->FindB("Acquire::http::No-Cache",false) == false)
   {
      // cache enabled
      if (_config->FindB("Acquire::http::No-Store",false) == true)
	 headers = curl_slist_append(headers,"Cache-Control: no-store");
      ioprintf(ss, "Cache-Control: max-age=%u", _config->FindI("Acquire::http::Max-Age",0));
      headers = curl_slist_append(headers, ss.str().c_str());
   } else {
      // cache disabled by user
      headers = curl_slist_append(headers, "Cache-Control: no-cache");
      headers = curl_slist_append(headers, "Pragma: no-cache");
   }
   curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

   // speed limit
   int dlLimit = _config->FindI("Acquire::http::Dl-Limit",0)*1024;
   if (dlLimit > 0)
      curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, dlLimit);

   // set header
   curl_easy_setopt(curl, CURLOPT_USERAGENT,"Debian APT-CURL/1.0 ("VERSION")");

   // debug
   if(_config->FindB("Debug::Acquire::https", false))
      curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

   // error handling
   curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errorstr);

   // if we have the file send an if-range query with a range header
   if (stat(Itm->DestFile.c_str(),&SBuf) >= 0 && SBuf.st_size > 0)
   {
      char Buf[1000];
      sprintf(Buf,"Range: bytes=%li-\r\nIf-Range: %s\r\n",
	      (long)SBuf.st_size - 1,
	      TimeRFC1123(SBuf.st_mtime).c_str());
      headers = curl_slist_append(headers, Buf);
   } 
   else if(Itm->LastModified > 0)
   {
      curl_easy_setopt(curl, CURLOPT_TIMECONDITION, CURL_TIMECOND_IFMODSINCE);
      curl_easy_setopt(curl, CURLOPT_TIMEVALUE, Itm->LastModified);
   }

   // go for it - if the file exists, append on it
   File = new FileFd(Itm->DestFile, FileFd::WriteAny);
   if (File->Size() > 0)
      File->Seek(File->Size() - 1);
   
   // keep apt updated
   Res.Filename = Itm->DestFile;

   // get it!
   CURLcode success = curl_easy_perform(curl);
   curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &curl_responsecode);

   long curl_servdate;
   curl_easy_getinfo(curl, CURLINFO_FILETIME, &curl_servdate);

   // cleanup
   if(success != 0) 
   {
      unlink(File->Name().c_str());
      _error->Error(curl_errorstr);
      Fail();
      return true;
   }
   File->Close();

   // Timestamp
   struct utimbuf UBuf;
   if (curl_servdate != -1) {
       UBuf.actime = curl_servdate;
       UBuf.modtime = curl_servdate;
       utime(File->Name().c_str(),&UBuf);
   }

   // check the downloaded result
   struct stat Buf;
   if (stat(File->Name().c_str(),&Buf) == 0)
   {
      Res.Filename = File->Name();
      Res.LastModified = Buf.st_mtime;
      Res.IMSHit = false;
      if (curl_responsecode == 304)
      {
	 unlink(File->Name().c_str());
	 Res.IMSHit = true;
	 Res.LastModified = Itm->LastModified;
	 Res.Size = 0;
	 URIDone(Res);
	 return true;
      }
      Res.Size = Buf.st_size;
   }

   // take hashes
   Hashes Hash;
   FileFd Fd(Res.Filename, FileFd::ReadOnly);
   Hash.AddFD(Fd.Fd(), Fd.Size());
   Res.TakeHashes(Hash);
   
   // keep apt updated
   URIDone(Res);

   // cleanup
   Res.Size = 0;
   delete File;
   curl_slist_free_all(headers);

   return true;
};

int main()
{
   setlocale(LC_ALL, "");

   HttpsMethod Mth;
   curl_global_init(CURL_GLOBAL_SSL) ;

   return Mth.Run();
}



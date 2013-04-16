--- src/contribs-lib/CLucene/snowball/Snowball.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/contribs-lib/CLucene/snowball/Snowball.cpp	2013-04-01 19:14:15.000000000 -0400
@@ -19,16 +19,31 @@
 
 CL_NS_DEF2(analysis,snowball)
 
+  class SnowballAnalyzer::SavedStreams : public TokenStream {
+  public:
+    StandardTokenizer* tokenStream;
+    TokenStream* filteredTokenStream;
+
+    SavedStreams():tokenStream(NULL), filteredTokenStream(NULL) {}
+    void close(){}
+    Token* next(Token* token) {return NULL;}
+  };
+  
   /** Builds the named analyzer with no stop words. */
   SnowballAnalyzer::SnowballAnalyzer(const TCHAR* language) {
     this->language = STRDUP_TtoT(language);
 	stopSet = NULL;
   }
 
-  SnowballAnalyzer::~SnowballAnalyzer(){
-	  _CLDELETE_CARRAY(language);
-	  if ( stopSet != NULL )
-		  _CLDELETE(stopSet);
+  SnowballAnalyzer::~SnowballAnalyzer() {
+    SavedStreams* streams = reinterpret_cast<SavedStreams*>(getPreviousTokenStream());
+    if (streams != NULL) {
+      _CLDELETE(streams->filteredTokenStream);
+      _CLDELETE(streams);
+    }
+    _CLDELETE_CARRAY(language);
+    if (stopSet != NULL)
+      _CLDELETE(stopSet);
   }
 
   /** Builds the named analyzer with the given stop words.
@@ -62,12 +77,29 @@
     result = _CLNEW SnowballFilter(result, language, true);
     return result;
   }
-  
-  
-  
-  
-  
-  
+
+  TokenStream* SnowballAnalyzer::reusableTokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader) {
+    SavedStreams* streams = reinterpret_cast<SavedStreams*>(getPreviousTokenStream());
+
+    if (streams == NULL) {
+      streams = _CLNEW SavedStreams();
+      BufferedReader* bufferedReader = reader->__asBufferedReader();
+
+      if (bufferedReader == NULL)
+        streams->tokenStream = _CLNEW StandardTokenizer(_CLNEW FilteredBufferedReader(reader, false), true);
+      else
+        streams->tokenStream = _CLNEW StandardTokenizer(bufferedReader);
+
+      streams->filteredTokenStream = _CLNEW StandardFilter(streams->tokenStream, true);
+      streams->filteredTokenStream = _CLNEW LowerCaseFilter(streams->filteredTokenStream, true);
+      if (stopSet != NULL)
+        streams->filteredTokenStream = _CLNEW StopFilter(streams->filteredTokenStream, true, stopSet);
+      streams->filteredTokenStream = _CLNEW SnowballFilter(streams->filteredTokenStream, language, true);
+      setPreviousTokenStream(streams);
+    } else
+      streams->tokenStream->reset(reader);
+    return streams->filteredTokenStream;
+  }
   
     /** Construct the named stemming filter.
    *

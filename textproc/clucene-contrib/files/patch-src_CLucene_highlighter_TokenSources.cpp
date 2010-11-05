--- src/CLucene/highlighter/TokenSources.cpp	Sat Feb 10 13:56:34 2007
+++ src/CLucene/highlighter/TokenSources.cpp.orig	Sat Nov 25 11:08:10 2006
@@ -27,12 +27,7 @@
 		//to TermPositionVector, we take the token stream
 		//only if the cast works... should have a way of
 		//knowing what type this is
-		TermPositionVector* tmp = NULL;
-		try{
-			 tmp = (TermPositionVector*)tfv;
-		}catch(...){
-			//ignore
-		}
+		TermPositionVector* tmp = tfv->__asTermPositionVector();
 		if ( tmp != NULL )
 		    ts=getTokenStream(tmp);
 	}
@@ -73,24 +68,21 @@
     }     */   
     //code to reconstruct the original sequence of Tokens
     const TCHAR** terms=tpv->getTerms();          
-    const int32_t* freq=tpv->getTermFrequencies();
-	int32_t freqLen = tpv->size();
+    const Array<int32_t>* freq=tpv->getTermFrequencies();
 
     size_t totalTokens=0;
-	{
-		for (int32_t t = 0; t < freqLen; t++)
-			totalTokens+=freq[t];
-	}
+	for (int32_t i = 0; i < freq->length; i++)
+		totalTokens+=freq->values[i];
 
     Token** tokensInOriginalOrder=NULL;
 	CLSetList<Token*,Token::OrderCompare>* unsortedTokens = NULL;
-    for (int32_t t = 0; t < freqLen; t++)
+    for (int32_t t = 0; t < freq->length; t++)
     {
-        TermVectorOffsetInfo** offsets=tpv->getOffsets(t);
+        Array<TermVectorOffsetInfo>* offsets=tpv->getOffsets(t);
         if(offsets==NULL)
             return NULL;
         
-        int32_t* pos=NULL;
+        Array<int32_t>* pos=NULL;
 		int32_t posLen=0;
         if(tokenPositionsGuaranteedContiguous)
         {
@@ -107,11 +99,11 @@
             //tokens NOT stored with positions or not guaranteed contiguous - must add to list and sort later
             if(unsortedTokens==NULL)
                 unsortedTokens=_CLNEW CLSetList<Token*,Token::OrderCompare>(false);
-            for (int32_t tp=0; offsets[tp]!=NULL; tp++)
+            for (int32_t tp=0; tp < offsets->length; tp++)
             {
                 unsortedTokens->insert(_CLNEW Token(terms[t],
-                    offsets[tp]->getStartOffset(),
-                    offsets[tp]->getEndOffset()));
+                    (*offsets)[tp].getStartOffset(),
+                    (*offsets)[tp].getEndOffset()));
             }
         }
         else
@@ -124,9 +116,9 @@
             //tokens stored with positions - can use this to index straight into sorted array
             for (int32_t tp = 0; tp < posLen; tp++)
             {
-                tokensInOriginalOrder[pos[tp]]=_CLNEW Token(terms[t],
-                        offsets[tp]->getStartOffset(),
-                        offsets[tp]->getEndOffset());
+                tokensInOriginalOrder[(*pos)[tp]]=_CLNEW Token(terms[t],
+                        (*offsets)[tp].getStartOffset(),
+                        (*offsets)[tp].getEndOffset());
             }                
         }
     }
@@ -158,13 +150,10 @@
 
 	//todo:bad way of doing this...
 	TermPositionVector* tmp = NULL;
-	try{
-		tmp = (TermPositionVector*) tfv; //check to see if tfv is a Tpv
-	}catch(...){}
+	tmp = tfv->__asTermPositionVector();
 
 	if ( tmp != NULL ){
-		TermPositionVector* tpv=(TermPositionVector*)reader->getTermFreqVector(docId,field);
-	    return getTokenStream(tpv);	        
+	    return getTokenStream(tmp);	        
 	}else{
 		TCHAR buf[250];
 		_sntprintf(buf,250,_T("%s in doc #%d does not have any term position data stored"),field,docId);

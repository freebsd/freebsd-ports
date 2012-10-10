--- extensions/spellcheck/hunspell/src/mozHunspell.cpp~
+++ extensions/spellcheck/hunspell/src/mozHunspell.cpp
@@ -344,6 +344,12 @@ mozHunspell::LoadDictionaryList()
     }
   }
 
+  // load system hunspell dictionaries
+  nsIFile* hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("%%LOCALBASE%%/share/hunspell"),
+			true, (nsILocalFile**)&hunDir);
+  LoadDictionariesFromDir(hunDir);
+
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
                    NS_GET_IID(nsISimpleEnumerator), getter_AddRefs(dictDirs));

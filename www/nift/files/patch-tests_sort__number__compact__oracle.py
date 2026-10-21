--- tests/sort_number_compact_oracle.py.orig	2026-10-20 16:24:32 UTC
+++ tests/sort_number_compact_oracle.py
@@ -22,7 +22,7 @@ std::cout<<"PASS actual candidate comparator "<<pairs<
 std::cout<<"PASS actual candidate comparator "<<pairs<<" Number pairs, both directions, full stable index order; key bytes="<<sizeof(Key)<<"\\n";}
 '''
 (p/'special-oracle.cpp').write_text(code)
-commands=[['g++','-std=c++17','-O2','-I'+str(r/'src'),'-I'+str(r/'include'),str(p/'special-oracle.cpp'),str(r/'src/RuntimeValue.cpp'),'-o',str(p/'special-oracle')],[str(p/'special-oracle')]]
+commands=[['c++','-std=c++17','-O2','-I'+str(r/'src'),'-I'+str(r/'include'),str(p/'special-oracle.cpp'),str(r/'src/RuntimeValue.cpp'),'-o',str(p/'special-oracle')],[str(p/'special-oracle')]]
 rows=[]
 for c in commands:
  q=subprocess.run(c,capture_output=True,text=True)

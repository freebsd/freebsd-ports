--- tinyldap.c.orig	Sat Mar 13 00:21:25 2004
+++ tinyldap.c	Fri Apr  2 13:15:39 2004
@@ -448,6 +448,83 @@
   }
 }
 
+static void answerall(uint32 ofs,long messageid,int out) {
+  struct SearchResultEntry sre;
+  struct PartialAttributeList** pal=&sre.attributes;
+
+  sre.objectName.l=bstrlen(sre.objectName.s=map+uint32_read(map+ofs+8));
+  sre.attributes=0;
+  /* now go through list of requested attributes */
+  {
+    uint32 adl=1,last=0;
+    struct string attr_key;
+
+    attr_key.s = NULL;
+    attr_key.l = 0;
+    uint32_unpack(map+ofs,&last);
+    while (adl < last) {
+      const char* att=0;
+      const char* val=0;
+      uint32 i=adl,j=last;
+
+      if (adl == 1) {
+         att="objectClass";
+	 val=map+uint32_read(map+ofs+12);
+      } else {
+         att=map+uint32_read(map+ofs+i*8);
+	 if (matchstring(&attr_key,att)) {
+	    val=map+uint32_read(map+ofs+i*8+4);
+	    ++i;
+         }
+      }
+      if (val) {
+	*pal=malloc(sizeof(struct PartialAttributeList));
+	if (!*pal) {
+nomem:
+	  buffer_putsflush(buffer_2,"out of virtual memory!\n");
+	  exit(1);
+	}
+        attr_key.s = att;
+        attr_key.l = strlen(att);
+	(*pal)->type=attr_key;
+	{
+	  struct AttributeDescriptionList** a=&(*pal)->values;
+add_attribute:
+	  *a=malloc(sizeof(struct AttributeDescriptionList));
+	  if (!*a) goto nomem;
+	  (*a)->a.s=bstrfirst(val);
+	  (*a)->a.l=bstrlen(val);
+	  for (;i<j; ++i)
+	    if (!matchstring(&attr_key,map+uint32_read(map+ofs+i*8))) {
+	      val=map+uint32_read(map+ofs+i*8+4);
+	      ++i;
+	      a=&(*a)->next;
+	      goto add_attribute;
+	    }
+	  (*a)->next=0;
+	}
+	(*pal)->next=0;
+	pal=&(*pal)->next;
+      }
+      adl++;
+    }
+  }
+  {
+    long l=fmt_ldapsearchresultentry(0,&sre);
+    char *buf=alloca(l+300); /* you never know ;) */
+    long tmp;
+    if (verbose) {
+      buffer_puts(buffer_2,"sre len ");
+      buffer_putulong(buffer_2,l);
+      buffer_putsflush(buffer_2,".\n");
+    }
+    tmp=fmt_ldapmessage(buf,messageid,SearchResultEntry,l);
+    fmt_ldapsearchresultentry(buf+tmp,&sre);
+    write(out,buf,l+tmp);
+  }
+  free_ldappal(sre.attributes);
+}
+
 static void answerwith(uint32 ofs,struct SearchRequest* sr,long messageid,int out) {
   struct SearchResultEntry sre;
   struct PartialAttributeList** pal=&sre.attributes;
@@ -483,6 +560,10 @@
   /* now go through list of requested attributes */
   {
     struct AttributeDescriptionList* adl=sr->attributes;
+    if ( adl == NULL ) {
+      answerall(ofs,messageid,out);
+      return;
+    }
     while (adl) {
       const char* val=0;
       uint32 i=2,j;

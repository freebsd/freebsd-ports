--- editview.cc.orig	2007-08-02 14:52:33.000000000 +0200
+++ editview.cc	2007-08-02 14:52:53.000000000 +0200
@@ -66,7 +66,7 @@
 	}
 	char str[256];
 	model_ = m;
-	sprintf(str, "def%-u", (int)this);
+	sprintf(str, "def%-u", (intptr_t)this);
 	defTag_ = new Tag(str);
 	model_->add_tag(defTag_);
 	editing_stage_ = NONE;
@@ -89,7 +89,7 @@
 	}
 
 	model_ = m;
-	sprintf(str, "def%-u", (int)this);
+	sprintf(str, "def%-u", (intptr_t)this);
 	defTag_ = new Tag(name);
 	model_->add_tag(defTag_);
 	editing_stage_ = NONE;

--- implementation/parser/parser/actions.cpp (revision 5607)
+++ implementation/parser/parser/actions.cpp (revision 5648)
@@ -1919,5 +1919,5 @@
 	if (modifier == CMS_ST_ARTICLECOMMENT)
 	{
-		if (!c.ArticleCommentEnabled())
+		if (!c.ArticleCommentEnabled() || c.ArticleComment() == NULL)
 		{
 			return ERR_NODATA;
@@ -2444,7 +2444,7 @@
 			run = c.ArticleCommentEnabled() ? 0 : 1;
 		}
-		else if (!c.ArticleCommentEnabled())
-		{
-				return ERR_NODATA;
+		else if (!c.ArticleCommentEnabled() || c.ArticleComment() == NULL)
+		{
+			return ERR_NODATA;
 		}
 		if (case_comp(param.attribute(), "Defined") == 0)
@@ -2872,7 +2872,11 @@
 	}
 	else
+	{
 		return -1;
+	}
 	if (modifier != CMS_ST_LANGUAGE && modifier != CMS_ST_PUBLICATION && param.attrType() == "")
+	{
 		SetNrField("IdPublication", c.Publication(), buf, w);
+	}
 	if (need_lang)
 	{
@@ -2883,7 +2887,11 @@
 	string coQuery = string("select ") + field + " from " + tables;
 	if (w.length())
+	{
 		coQuery += string(" where ") + w;
+	}
 	if (need_lang)
+	{
 		coQuery += " order by IdLanguage desc";
+	}
 	DEBUGAct("takeAction()", coQuery.c_str(), fs);
 	SQLQuery(&m_coSql, coQuery.c_str());
@@ -2892,5 +2900,7 @@
 	FetchRow(*res, row);
 	if (row[0] == NULL)
+	{
 		return ERR_NODATA;
+	}
 	if (modifier == CMS_ST_ARTICLE && param.attrType() != "" && !m_bStrictType)
 	{
@@ -2928,10 +2938,16 @@
 	}
 	else
+	{
 		run_first = row[0] == value;
+	}
 	run_first = m_bNegated ? !run_first : run_first;
 	if (run_first)
+	{
 		runActions(block, c, fs);
+	}
 	else
+	{
 		runActions(sec_block, c, fs);
+	}
 	return RES_OK;
 	TK_CATCH_ERR

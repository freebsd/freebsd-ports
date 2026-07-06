--- iris/src/xmpp/xmpp-im/types.cpp.orig	2020-09-06 07:44:45 UTC
+++ iris/src/xmpp/xmpp-im/types.cpp
@@ -2275,8 +2275,7 @@ bool Subscription::fromString(const QString &s)
 /**
  * Default constructor.
  */
-CapsSpec::CapsSpec() :
-    hashAlgo_(CapsSpec::invalidAlgo)
+CapsSpec::CapsSpec()
 {
 }
 
@@ -2287,7 +2286,7 @@ CapsSpec::CapsSpec() :
  * @param ven the version
  * @param ext the list of extensions (separated by spaces)
  */
-CapsSpec::CapsSpec(const QString& node, QCryptographicHash::Algorithm hashAlgo, const QString& ver)
+CapsSpec::CapsSpec(const QString& node, XMPP::CapsSpec::AlgoOpt hashAlgo, const QString& ver)
 	: node_(node)
 	, ver_(ver)
     , hashAlgo_(hashAlgo)
@@ -2305,7 +2304,7 @@ CapsSpec::CapsSpec(const DiscoItem &disco, QCryptograp
  */
 bool CapsSpec::isValid() const
 {
-	return !node_.isEmpty() && !ver_.isEmpty() && (hashAlgo_ != CapsSpec::invalidAlgo);
+	return !node_.isEmpty() && !ver_.isEmpty() && hashAlgo_;
 }
 
 
@@ -2326,7 +2325,7 @@ const QString& CapsSpec::version() const
 	return ver_;
 }
 
-QCryptographicHash::Algorithm CapsSpec::hashAlgorithm() const
+XMPP::CapsSpec::AlgoOpt CapsSpec::hashAlgorithm() const
 {
 	return hashAlgo_;
 }
@@ -2335,8 +2334,7 @@ QDomElement CapsSpec::toXml(QDomDocument *doc) const
 {
 	QDomElement c = doc->createElement("c");
 	c.setAttribute("xmlns", NS_CAPS);
-	QString algo = cryptoMap().key(hashAlgo_);
-	c.setAttribute("hash",algo);
+	c.setAttribute("hash", hashAlgo_ ? cryptoMap().key(*hashAlgo_) : "");
 	c.setAttribute("node",node_);
 	c.setAttribute("ver",ver_);
 	return c;
@@ -2351,7 +2349,7 @@ CapsSpec CapsSpec::fromXml(const QDomElement &e)
 	CryptoMap &cm = cryptoMap();
 	CapsSpec cs;
 	if (!node.isEmpty() && !ver.isEmpty()) {
-		QCryptographicHash::Algorithm algo = CapsSpec::invalidAlgo;
+		tl::optional<QCryptographicHash::Algorithm> algo;
 		CryptoMap::ConstIterator it;
 		if (!hashAlgo.isEmpty() && (it = cm.constFind(hashAlgo)) != cm.constEnd()) {
 			algo = it.value();

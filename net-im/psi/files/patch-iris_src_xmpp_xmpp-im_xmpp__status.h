--- iris/src/xmpp/xmpp-im/xmpp_status.h.orig	2020-09-06 11:27:29 UTC
+++ iris/src/xmpp/xmpp-im/xmpp_status.h
@@ -27,6 +27,8 @@
 #include <QDateTime>
 #include <QCryptographicHash>
 
+#include "../../../../tlo/include/tl/optional.hpp"
+
 #include "xmpp_muc.h"
 #include "xmpp_bitsofbinary.h"
 
@@ -37,16 +39,16 @@ namespace XMPP
 	{
 		public:
 			typedef QMap<QString,QCryptographicHash::Algorithm> CryptoMap;
-			static const QCryptographicHash::Algorithm invalidAlgo = (QCryptographicHash::Algorithm)255;
+			using AlgoOpt = tl::optional<QCryptographicHash::Algorithm>;
 
 			CapsSpec();
-            CapsSpec(const QString& node, QCryptographicHash::Algorithm hashAlgo, const QString& ver = QString());
+			CapsSpec(const QString& node, AlgoOpt hashAlgo, const QString& ver = QString());
 			CapsSpec(const DiscoItem &disco, QCryptographicHash::Algorithm hashAlgo = QCryptographicHash::Sha1);
 
 			bool isValid() const;
 			const QString& node() const;
 			const QString& version() const;
-			QCryptographicHash::Algorithm hashAlgorithm() const;
+			AlgoOpt hashAlgorithm() const;
 			inline const QStringList &ext() const { return ext_; }
 			QString flatten() const;
 
@@ -63,7 +65,7 @@ namespace XMPP
 
 		private:
 			QString node_, ver_;
-			QCryptographicHash::Algorithm hashAlgo_;
+			AlgoOpt hashAlgo_;
 			QStringList ext_;
 	};
 

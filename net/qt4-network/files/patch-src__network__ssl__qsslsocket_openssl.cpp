--- ./src/network/ssl/qsslsocket_openssl.cpp.orig	2010-11-06 04:55:18.000000000 +0300
+++ ./src/network/ssl/qsslsocket_openssl.cpp	2010-11-12 00:05:19.726416792 +0300
@@ -777,6 +777,7 @@
     systemCerts.append(QSslCertificate::fromPath(QLatin1String("/opt/openssl/certs/*.pem"), QSsl::Pem, QRegExp::Wildcard)); // HP-UX
     systemCerts.append(QSslCertificate::fromPath(QLatin1String("/etc/ssl/certs/*.pem"), QSsl::Pem, QRegExp::Wildcard)); // (K)ubuntu, OpenSUSE, Mandriva, ...
     systemCerts.append(QSslCertificate::fromPath(QLatin1String("/etc/pki/tls/certs/ca-bundle.crt"), QSsl::Pem)); // Fedora
+    systemCerts.append(QSslCertificate::fromPath(QLatin1String("/usr/local/share/certs/ca-root-nss.crt"), QSsl::Pem)); // FreeBSD's ca_root_nss
     systemCerts.append(QSslCertificate::fromPath(QLatin1String("/usr/lib/ssl/certs/*.pem"), QSsl::Pem, QRegExp::Wildcard)); // Gentoo, Mandrake
     systemCerts.append(QSslCertificate::fromPath(QLatin1String("/usr/share/ssl/*.pem"), QSsl::Pem, QRegExp::Wildcard)); // Centos, Redhat, SuSE
     systemCerts.append(QSslCertificate::fromPath(QLatin1String("/usr/local/ssl/*.pem"), QSsl::Pem, QRegExp::Wildcard)); // Normal OpenSSL Tarball

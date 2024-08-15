PORTNAME=	libetpan
PORTVERSION=	1.9.4
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mail framework for C language
WWW=		https://www.etpan.org/libetpan.html \
		https://github.com/dinhvh/libetpan

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libsasl2.so:security/cyrus-sasl2

USES=		autoreconf compiler:c++11-lang cpe gmake iconv libtool localbase pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPE_VENDOR=	libetpan_project

USE_GITHUB=	yes
GH_ACCOUNT=	dinhviethoa

OPTIONS_DEFINE=	IPV6
OPTIONS_SINGLE=	CRYPTO
OPTIONS_SINGLE_CRYPTO=	GNUTLS OPENSSL
OPTIONS_DEFAULT=OPENSSL

GNUTLS_CONFIGURE_ON=	--without-openssl --with-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
IPV6_CONFIGURE_ENABLE=	ipv6
OPENSSL_CONFIGURE_WITH=	openssl="${OPENSSLBASE}"
OPENSSL_USES=		ssl

.include <bsd.port.mk>

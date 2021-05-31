# Created by: David Barksdale <amatus@gnu.org>

PORTNAME=	libmicrohttpd
DISTVERSION=	0.9.73
CATEGORIES=	www
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix
USE_LDCONFIG=	yes
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-examples

OPTIONS_DEFINE=		GNUTLS TESTCURL
OPTIONS_DEFAULT=	GNUTLS
TESTCURL_DESC=		Use curl when running unit tests

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls
GNUTLS_USES=		localbase
GNUTLS_CONFIGURE_ENABLE=https

TESTCURL_LIB_DEPENDS=	libcurl.so:ftp/curl
TESTCURL_CONFIGURE_OFF=	--disable-curl

INFO=			libmicrohttpd libmicrohttpd-tutorial

.include <bsd.port.mk>

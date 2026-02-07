PORTNAME=	libmicrohttpd
DISTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality
WWW=		https://www.gnu.org/software/libmicrohttpd/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool localbase pathfix
USE_LDCONFIG=	yes
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes

INFO=		libmicrohttpd libmicrohttpd-tutorial
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-examples

OPTIONS_DEFINE=		GNUTLS TESTCURL
OPTIONS_DEFAULT=	GNUTLS

TESTCURL_DESC=		Use curl when running unit tests

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=https

TESTCURL_LIB_DEPENDS=	libcurl.so:ftp/curl
TESTCURL_CONFIGURE_ENABLE=	curl

.include <bsd.port.mk>

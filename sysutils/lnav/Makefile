# Created by: Thomas Hurst <tom@hur.st>

PORTNAME=	lnav
PORTVERSION=	0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tstack/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	tom@hur.st
COMMENT=	Terminal based log file navigator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcrecpp.so:devel/pcre

USES=		autoreconf compiler:c++14-lang gmake ncurses readline sqlite tar:bz2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

PLIST_FILES=	bin/lnav man/man1/lnav.1.gz

OPTIONS_DEFINE=	CURL
OPTIONS_DEFAULT=CURL
CURL_DESC=	Use libcurl for remote log file support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lnav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lnav.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

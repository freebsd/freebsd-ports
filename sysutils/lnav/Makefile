# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	lnav
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Terminal based log file navigator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcrecpp.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	tstack

USES=		autoreconf compiler:c++14-lang gmake ncurses sqlite readline
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

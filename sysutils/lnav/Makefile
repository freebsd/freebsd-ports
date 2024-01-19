PORTNAME=	lnav
DISTVERSION=	0.11.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tstack/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	tom@hur.st
COMMENT=	Terminal based log file navigator
WWW=		https://lnav.org/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		autoreconf compiler:c++14-lang gmake ncurses readline sqlite \
		tar:bz2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

PLIST_FILES=	bin/lnav \
		share/man/man1/lnav.1.gz

OPTIONS_DEFINE=		CURL
OPTIONS_DEFAULT=	CURL
CURL_DESC=		Use libcurl for remote log file support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lnav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lnav.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

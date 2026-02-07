PORTNAME=	lnav
DISTVERSION=	0.12.3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tstack/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	tom@hur.st
COMMENT=	Terminal-based log file navigator
WWW=		https://lnav.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre2-8.so:devel/pcre2

USES=		autoreconf compiler:c++17-lang gmake ncurses readline sqlite \
		tar:bz2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

PLIST_FILES=	bin/lnav \
		share/man/man1/lnav.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lnav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lnav.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

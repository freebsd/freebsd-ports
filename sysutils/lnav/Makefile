PORTNAME=	lnav
DISTVERSION=	0.12.2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tstack/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	tom@hur.st
COMMENT=	Terminal-based log file navigator
WWW=		https://lnav.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_15=	compilation fails with clang-19 but future 0.12.3 will include fix: https://github.com/tstack/lnav/issues/1328

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre2-8.so:devel/pcre2

USES=		autoreconf compiler:c++14-lang gmake ncurses readline sqlite \
		tar:bz2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

PLIST_FILES=	bin/lnav \
		share/man/man1/lnav.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lnav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lnav.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

PORTNAME=	lnav
DISTVERSION=	0.14.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tstack/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	marcel@herrbischoff.com
COMMENT=	Terminal-based log file navigator
WWW=		https://lnav.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	./time_util.hh:324:9: error: non-constant-expression cannot be narrowed from type 'rep' (aka 'long long') to 'time_t' (aka 'int') in initializer list [-Wc++11-narrowing]

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre2-8.so:devel/pcre2 \
		libunistring.so:devel/libunistring

USES=		autoreconf compiler:c++17-lang gmake localbase ncurses sqlite \
		tar:bz2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

PLIST_FILES=	bin/lnav \
		share/man/man1/lnav.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lnav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lnav.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

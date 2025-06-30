PORTNAME=		sc-im
DISTVERSIONPREFIX=	v
DISTVERSION=		0.8.5
PORTREVISION=	1
CATEGORIES=		math

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Ncurses spreadsheet program for terminal
WWW=		https://github.com/andmarti1424/sc-im

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libxlsreader.so:math/libxls \
		libxlsxwriter.so:math/libxlsxwriter \
		libzip.so:archivers/libzip

USES=		compiler:c11 gmake gnome lua ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	andmarti1424
USE_GNOME=	libxml2

WRKSRC_SUBDIR=	src
CFLAGS+=	-DXLSX_EXPORT -DXLS
LIBS+=		-lxlsreader -lxlsxwriter
MAKE_ENV+=	LDLIBS="${LIBS}" LUA_PKGNAME=lua-${LUA_VER}
MAKE_ARGS+=	CC="${CC}" prefix="${PREFIX}" MANDIR="${PREFIX}/share/man/man1" THEMEDIR="${DATADIR}/themes"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sc-im
	${RM} ${STAGEDIR}${PREFIX}/bin/scopen

.include <bsd.port.mk>

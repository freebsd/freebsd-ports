PORTNAME=		sc-im
DISTVERSIONPREFIX=	v
DISTVERSION=		0.8.2
PORTREVISION=		1
CATEGORIES=		math

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Ncurses spreadsheet program for terminal

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libxlsreader.so:math/libxls \
		libxlsxwriter.so:math/libxlsxwriter \
		libzip.so:archivers/libzip

USES=		compiler:c11 gmake gnome lua:51 ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	andmarti1424
USE_GNOME=	libxml2

WRKSRC_SUBDIR=	src
CFLAGS+=	-DXLSX_EXPORT -DXLS
LIBS+=		-lxlsreader -lxlsxwriter
MAKE_ENV+=	LDLIBS="${LIBS}"
MAKE_ARGS+=	CC="${CC}" prefix="${PREFIX}" MANDIR="${MANPREFIX}/man/man1"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sc-im
	${RM} ${STAGEDIR}${PREFIX}/bin/scopen

.include <bsd.port.mk>

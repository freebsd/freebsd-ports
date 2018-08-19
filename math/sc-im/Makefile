# $FreeBSD$

PORTNAME=		sc-im
PORTVERSION=		0.7.0
DISTVERSIONPREFIX=	v
PORTREVISION=		1
CATEGORIES=		math

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Ncurses spreadsheet program for terminal

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libxlsreader.so:math/libxls \
		libzip.so:archivers/libzip \
		libxlsxwriter.so:math/libxlsxwriter

USES=		gmake pkgconfig lua:51 ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	andmarti1424
USE_GNOME=	libxml2

WRKSRC_SUBDIR=	src
CFLAGS+=	-DXLSX_EXPORT -DXLS
LIBS+=		-lxlsreader -lxlsxwriter
MAKE_ENV+=	LDLIBS="${LIBS}"
MAKE_ARGS+=	CC="${CC}" prefix="${PREFIX}" MANDIR="${MANPREFIX}/man/man1"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/scim

.include <bsd.port.mk>

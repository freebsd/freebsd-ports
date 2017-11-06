# $FreeBSD$

PORTNAME=	sc-im
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Ncurses spreadsheet program for terminal

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libxlsreader.so:math/libxls \
		libzip.so:archivers/libzip \
		libxlsxwriter.so:math/libxlsxwriter

USES=		gmake pkgconfig lua:51
USE_GITHUB=	yes
GH_ACCOUNT=	andmarti1424
USE_GNOME=	libxml2

WRKSRC_SUBDIR=	src
CFLAGS+=	-DXLSX_EXPORT -DXLS
LIBS+=		-lxlsreader -lxlsxwriter
MAKE_ENV+=	LDLIBS="${LIBS}"
MAKE_ARGS+=	CC="${CC}" prefix="${PREFIX}" MANDIR="${MANPREFIX}/man/man1"

PLIST_FILES=	bin/scim \
		man/man1/scim.1.gz \
		share/scim/scim_help

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/scim

.include <bsd.port.mk>

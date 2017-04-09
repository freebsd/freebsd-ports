# $FreeBSD$

PORTNAME=	sc-im
PORTVERSION=	0.5.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Ncurses spreadsheet program for terminal

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libxlsreader.so:math/libxls \
		libzip.so:archivers/libzip

USES=		gmake localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	andmarti1424
USE_GNOME=	libxml2

WRKSRC_SUBDIR=	src
CFLAGS+=	-I${LOCALBASE}/include/libxml2
MAKE_ENV+=	LDLIBS="${LIBS}"
MAKE_ARGS+=	CC="${CC}" prefix="${PREFIX}" MANDIR="${MANPREFIX}/man/man1"

PLIST_FILES=	bin/scim \
		man/man1/scim.1.gz \
		share/scim/scim_help

.include <bsd.port.mk>

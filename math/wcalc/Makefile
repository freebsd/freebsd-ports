# Created by: Amarendra Godbole <amarendra.godbole@gmail.com>
# $FreeBSD$

PORTNAME=	wcalc
PORTVERSION=	2.4
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/w-calc/Wcalc/${PORTVERSION}
DISTNAME=	wcalc-${PORTVERSION}

MAINTAINER=	amarendra.godbole@gmail.com
COMMENT=	A natural-expression command-line calculator

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/wcalc \
		man/man1/wcalc.1.gz

.include <bsd.port.mk>

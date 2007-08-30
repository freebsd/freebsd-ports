# New ports collection makefile for:	wcalc
# Date created:			25-Apr-2007
# Whom:				Amarendra Godbole <amarendra.godbole@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wcalc
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	w-calc
DISTNAME=	Wcalc-${PORTVERSION}

MAINTAINER=	amarendra.godbole@gmail.com
COMMENT=	A natural-expression command-line calculator

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4 \
		mpfr.2:${PORTSDIR}/math/mpfr

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		wcalc.1

PLIST_FILES=	bin/wcalc

.include <bsd.port.mk>

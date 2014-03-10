# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drgeo
PORTVERSION=	1.1.0
PORTREVISION=	15
CATEGORIES=	math
MASTER_SITES=	SF/ofset/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GTK interactive geometry software

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehack gnomeprefix intlhack libglade2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GCC=	yes # segfaults when built with clang

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/plugin/drgeo/progs/tm_drgeo

.include <bsd.port.mk>

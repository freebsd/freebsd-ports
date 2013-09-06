# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drgeo
PORTVERSION=	1.1.0
PORTREVISION=	14
CATEGORIES=	math
MASTER_SITES=	SF/ofset/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GTK interactive geometry software

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile

USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehack gnomeprefix intlhack libglade2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GCC=	any # doesn't link otherwise

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/plugin/drgeo/progs/tm_drgeo

.include <bsd.port.mk>

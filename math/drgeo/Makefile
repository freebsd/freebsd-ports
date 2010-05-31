# New ports collection makefile for:	drgenius
# Date created:				11 January 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drgeo
PORTVERSION=	1.1.0
PORTREVISION=	12
CATEGORIES=	math
MASTER_SITES=	SF/ofset/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A GTK interactive geometry sofware

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile

USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/plugin/drgeo/progs/tm_drgeo

.include <bsd.port.mk>

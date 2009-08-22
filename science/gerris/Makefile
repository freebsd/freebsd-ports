# ex:ts=8
# New ports collection makefile for:   gerris
# Date created:                        Sun Sep 18 12:36:38 CEST 2005
# Whom:                                Oliver Dunkl <odunkl@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	gerris
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	science math
MASTER_SITES=	SF/gfs/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific CFD simulator

LIB_DEPENDS=	gts.5:${PORTSDIR}/graphics/gts

USE_GNOME=	glib20 gnomehack pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mpi
USE_LDCONFIG=	yes

.if defined(WITHOUT_DX)
CONFIGURE_ARGS+=	--disable-dx
PLIST_SUB+=	DX="@comment "
.else
BUILD_DEPENDS+=		dx:${PORTSDIR}/graphics/opendx
RUN_DEPENDS+=		dx:${PORTSDIR}/graphics/opendx
PLIST_SUB+=	DX=""
.endif

.include <bsd.port.mk>

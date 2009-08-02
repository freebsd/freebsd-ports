# New ports collection makefile for:   gnome-device-manager
# Date Created:			08 January 2008
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-device-manager/Makefile,v 1.1 2008/01/08 06:47:29 marcus Exp $
#

PORTNAME=	gnome-device-manager
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	HAL device manager for the GNOME Desktop

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget intlhack ltverhack libgnomeui
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

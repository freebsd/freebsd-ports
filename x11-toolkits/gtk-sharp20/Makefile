# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	0.7
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-sharp

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
LIB_DEPENDS=	gnomedb-2:${PORTSDIR}/databases/libgnomedb \
		gnomeui-2:${PORTSDIR}/x11-toolkits/libgnomeui

# XXX Should conditionalise all the different parts of gtk# maybe.

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

.include <bsd.port.mk>

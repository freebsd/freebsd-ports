# New ports collection makefile for:	xfce-wavelan-plugin
# Date created:				22 May 2004
# Whom:					Manuel Rabade Garica <mig@mig-29.net
#
# $FreeBSD$
#

PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/ \
		http://matt.nerim.net/xfce-goodies/ \
		http://xfce.org/~kelnos/mirrors/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	mig@mig-29.net
COMMENT=	Displays various information about a WaveLAN device

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>

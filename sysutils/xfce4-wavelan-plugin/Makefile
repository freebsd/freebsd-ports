# New ports collection makefile for:	xfce-wavelan-plugin
# Date created:				22 May 2004
# Whom:					Manuel Rabade Garica <mig@mig-29.net>
#
# $FreeBSD$
#    $MCom: ports/sysutils/xfce4-wavelan-plugin/Makefile,v 1.1 2006/10/02 20:43:59 ahze Exp $

PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays various information about a WaveLAN device

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>

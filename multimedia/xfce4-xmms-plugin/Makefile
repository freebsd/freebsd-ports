# New ports collection makefile for:	xfce4-xmms-plugin
# Date created:				2004/05/10
# Whom:					Zahemszky, Gábor <Gabor@Zahemszky.HU>
#
# $FreeBSD$
#

PORTNAME=	xfce4-xmms-plugin
PORTVERSION=	0.3.1
CATEGORIES=	multimedia audio xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/ \
		http://download2.berlios.de/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	jfb@minet.net
COMMENT=	XFce 4 xmms control plugin for xfce4-panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xmms:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

.include <bsd.port.mk>

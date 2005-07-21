# New ports collection makefile for:   xfce4-xmms-controller-plugin
# Date created:        8 Nov 2004
# Whom:                Robin Schoonover (endx7@users.sf.net)
#
# $FreeBSD$
#

PORTNAME=	xfce4-xmms-controller-plugin
PORTVERSION=	1.4.3
PORTREVISION=	2
CATEGORIES=	multimedia audio xfce
MASTER_SITES=	http://eoin.angrystickman.com/files/
DIST_SUBDIR=	xfce4

MAINTAINER=	robin.schoonover@gmail.com
COMMENT=	XMMS controller plugin for the xfce4 panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500043
IGNORE=		requires pthread stubs not provided by libXThr
.endif

pre-patch:
	${REINPLACE_CMD} -e 's_share/_share/xfce4-xmms-controller-plugin/_' ${WRKSRC}/panel-plugin/xfcexmms.c
	${REINPLACE_CMD} -e 's_/usr/local_${PREFIX}_' ${WRKSRC}/config.h.in

.include <bsd.port.post.mk>

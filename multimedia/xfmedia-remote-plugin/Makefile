# New ports collection makefile for:	xfmedia-remote-plugin
# Date created:				2007/09/24
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfmedia-remote-plugin
PORTVERSION=	0.2.2
PORTREVISION=	11
CATEGORIES=	multimedia audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins//${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 media remote plugin for xfce4-panel

BUILD_DEPENDS=	xfce4-media>=0.9.2:${PORTSDIR}/multimedia/xfce4-media

BROKEN=		Does not work with Xfce 4.8

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel

.include <bsd.port.mk>

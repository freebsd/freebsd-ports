# New ports collection makefile for:	xfmedia-remote-plugin
# Date created:				2007/09/24
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfmedia-remote-plugin
PORTVERSION=	0.2.2
PORTREVISION=	10
CATEGORIES=	multimedia audio xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	XFce 4 media remote plugin for xfce4-panel

BUILD_DEPENDS=	xfce4-media>=0.9.2:${PORTSDIR}/multimedia/xfce4-media

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel

.include <bsd.port.mk>

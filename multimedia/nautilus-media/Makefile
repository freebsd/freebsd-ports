# New ports collection makefile for:	nautilus-media
# Date created:				30 November 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-media
PORTVERSION=	0.3.3.1
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GStreamer-based multimedia views for Nautilus

LIB_DEPENDS=	gstplay-0.6.1:${PORTSDIR}/multimedia/gstreamer-plugins

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack nautilus2
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

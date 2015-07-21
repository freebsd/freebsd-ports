# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer1-editing-services
PORTVERSION=	1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer-editing-services/
DISTNAME=	gstreamer-editing-services-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gstreamer editing services

PORTSCOUT=	limitw:1,even

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build libxml2
USE_GSTREAMER1=	gnonlin
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-introspection=yes
PLIST_SUB=	VERSION=1.0

.include <bsd.port.mk>

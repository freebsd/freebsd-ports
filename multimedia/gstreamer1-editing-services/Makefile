# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer1-editing-services
PORTVERSION=	1.8.0
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer-editing-services/
DISTNAME=	gstreamer-editing-services-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer editing services

PORTSCOUT=	limitw:1,even

USES=		gmake libtool pathfix python:2 pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build libxml2
USE_GSTREAMER1=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-introspection=yes \
		--with-bash-completion-dir=${PREFIX}/share/bash-completion/completions
PLIST_SUB=	VERSION=1.0 SOVERSION=0.800.0

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

.include <bsd.port.mk>

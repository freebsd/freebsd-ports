PORTNAME=	gstreamer1-editing-services
PORTVERSION=	1.20.5
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer-editing-services/
DISTNAME=	gst-editing-services-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer editing services
WWW=		http://gstreamer.freedeskop.org

LICENSE=	LGPL20

USES=		bison compiler:c11 gnome gstreamer meson ninja python:3.8+ pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build libxml2 pygobject3:build
USE_GSTREAMER=	good bad
LIB_DEPENDS+=	libgstvalidate-1.0.so:multimedia/gstreamer1-validate
PORTSCOUT=	limitw:1,even

CONFIGURE_ARGS=	-Ddoc=disabled \
		-Dintrospection=enabled \
		-Dpygi-overrides-dir=${PYTHON_SITELIBDIR}/gstreamer-editing-services
PLIST_SUB=	VERSION=1.0 SOVERSION=0.2005.0

BINARY_ALIAS=	python3=${PYTHON_VERSION}

post-install:
	${MKDIR} ${PREFIX}/share/bash-completion/completions
	${INSTALL_SCRIPT} ${WRKSRC}/data/completions/ges-launch-1.0 \
	${STAGEDIR}${PREFIX}/share/bash-completion/completions/

.include <bsd.port.mk>

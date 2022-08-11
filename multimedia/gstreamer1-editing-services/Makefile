PORTNAME=	gstreamer1-editing-services
PORTVERSION=	1.16.3
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer-editing-services/
DISTNAME=	gstreamer-editing-services-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer editing services

LICENSE=	LGPL20

USES=		compiler:c11 gnome gstreamer meson python pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build libxml2 pygobject3:build
USE_GSTREAMER=	good bad
LIB_DEPENDS+=	libgstvalidate-1.0.so:multimedia/gstreamer1-validate
PORTSCOUT=	limitw:1,even

CONFIGURE_ARGS=	-D gtk_doc=disabled \
		-D introspection=enabled \
		-D pygi-overrides-dir=${PYTHON_SITELIBDIR}/gstreamer-editing-services
PLIST_SUB=	VERSION=1.0 SOVERSION=0.1603.0

post-install:
		${MKDIR} ${PREFIX}/share/bash-completion/completions
		${INSTALL_SCRIPT} ${WRKSRC}/data/completions/ges-launch-1.0 \
			${STAGEDIR}${PREFIX}/share/bash-completion/completions/

.include <bsd.port.mk>

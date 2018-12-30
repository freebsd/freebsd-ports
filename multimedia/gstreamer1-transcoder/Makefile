# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer1-transcoder
PORTVERSION=	1.14.1
CATEGORIES=	multimedia

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GStreamer Transcoding API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc

USES=		gnome meson pkgconfig python:3.3+ #shebangfix
USE_GNOME=	introspection
USE_GSTREAMER1=	core
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_VERSION}
#SHEBANG_FILES=	configure

USE_GITHUB=	yes
GH_ACCOUNT=	pitivi
GH_PROJECT=	gst-transcoder

post-patch:
.if exists(/usr/lib/libstdc++.so)
	${REINPLACE_CMD} -e '/-Wno-pedantic/d' \
		${WRKSRC}/meson.build
.endif

.include <bsd.port.mk>

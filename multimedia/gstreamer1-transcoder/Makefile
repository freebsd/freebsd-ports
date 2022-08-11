PORTNAME=	gstreamer1-transcoder
PORTVERSION=	1.16.0
CATEGORIES=	multimedia

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GStreamer Transcoding API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler gnome gstreamer meson pkgconfig python:3.3+ #shebangfix
USE_GNOME=	introspection
USE_GSTREAMER=	core
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_VERSION}
#SHEBANG_FILES=	configure

USE_GITHUB=	yes
GH_ACCOUNT=	pitivi
GH_PROJECT=	gst-transcoder

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
DOCS_MESON_FALSE=	disable_doc
DOCSDIR=		${PREFIX}/share/gtk-doc/html/gstreamer-transcoder/

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} -e '/-Wno-pedantic/d' \
		${WRKSRC}/meson.build
.endif

.include <bsd.port.post.mk>

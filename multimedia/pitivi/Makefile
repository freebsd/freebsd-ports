# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pitivi
PORTVERSION=	0.999
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor

LICENSE=	LGPL21+

BUILD_DEPENDS=	gst-validate-launcher:multimedia/gstreamer1-validate \
		itstool:textproc/itstool
LIB_DEPENDS=	libgsttranscoder-1.0.so:multimedia/gstreamer1-transcoder
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.14.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYNUMPY}

USES=		desktop-file-utils gettext gnome meson pkgconfig python:3.3+ shebangfix tar:xz
SHEBANG_FILES=	bin/pitivi.in \
		getenvvar.py \
		tests/__init__.py \
		tests/validate-tests/manager.py \
		tests/validate-tests/runtests
USE_GNOME=	cairo intltool gdkpixbuf2 gsound gtk30 pygobject3
USE_GSTREAMER1=	editing-services gdkpixbuf good gtk
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
MESON_ARGS=	-Db_lundef=false

post-patch:
	${REINPLACE_CMD} -e "/find_program/s|'python3'|'${PYTHON_VERSION}'|" \
		-e "/dependency/s|'python3'|'python-${PYTHON_VER}'|" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>

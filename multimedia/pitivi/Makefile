PORTNAME=	pitivi
PORTVERSION=	2022.06
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor
WWW=		https://www.pitivi.org

LICENSE=	LGPL21+

BUILD_DEPENDS=	gst-validate-launcher:multimedia/gstreamer1-validate \
		itstool:textproc/itstool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.14.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYNUMPY}

USES=		cpe desktop-file-utils gettext gnome gstreamer meson pkgconfig python \
		shared-mime-info shebangfix tar:xz
SHEBANG_FILES=	bin/pitivi.in \
		getenvvar.py \
		tests/__init__.py \
		tests/validate-tests/manager.py \
		tests/validate-tests/runtests
USE_GNOME=	cairo intltool gdkpixbuf gsound gtk30 pygobject3
USE_GSTREAMER=	bad editing-services gdkpixbuf good gtk
USE_LDCONFIG=	yes
MESON_ARGS=	-Db_lundef=false

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>

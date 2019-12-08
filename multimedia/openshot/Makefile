# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	openshot
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.4-443
DISTVERSIONSUFFIX=	-g7351f506
CATEGORIES=	multimedia

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Video Editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/openshot.py:multimedia/libopenshot \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

NO_ARCH=	yes
USES=		desktop-file-utils pyqt:5 python:3.5+ shared-mime-info shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
GH_PROJECT=	${PORTNAME}-qt
USE_PYQT=	core gui svg webkitwidgets widgets
USE_PYTHON=	distutils noflavors

SHEBANG_FILES=	src/language/generate_translations.py\
		src/language/show_translations.py\
		src/language/test_translations.py

.include <bsd.port.mk>

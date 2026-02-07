PORTNAME=	kartograph
DISTVERSION=	0.6.8
PORTREVISION=	5
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for building interactive map applications
WWW=		https://kartograph.org/docs/kartograph.py/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdal>0:graphics/py-gdal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordereddict>0:devel/py-ordereddict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyshp>0:devel/py-pyshp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>0:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pykml>0:misc/py-pykml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=1.0.14:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss>0:textproc/py-tinycss@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}.py
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

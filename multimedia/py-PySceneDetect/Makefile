# $FreeBSD$

PORTNAME=	PySceneDetect
PORTVERSION=	0.5.4
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	OpenCV-based video scene detection program and Python library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}click>=3.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opencv>=0:graphics/py-opencv@${PY_FLAVOR} \
		mkvmerge:multimedia/mkvtoolnix

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	Breakthrough
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

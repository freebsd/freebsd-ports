# $FreeBSD$

PORTNAME=	PySceneDetect
PORTVERSION=	0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	OpenCV-based video scene detection program and Python library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		mkvmerge:multimedia/mkvtoolnix \
		${PYTHON_PKGNAMEPREFIX}opencv>=0:graphics/py-opencv@${PY_FLAVOR}

USES=		python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	Breakthrough
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

PORTNAME=	numpy-stl
DISTVERSION=	2.11.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Simple library to make working with STL files fast and easy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}python-utils>=2.3.0:misc/py-python-utils@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	cython distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/stl/_speedups*.so

.include <bsd.port.mk>

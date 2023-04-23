PORTNAME=	uhi
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Histogram Interface
WWW=		https://uhi.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-histogram>=1.0:misc/py-boost-histogram@${PY_FLAVOR}

USES=		compiler:c++14-lang python:3.8+
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

pre-configure: # uhi is officially built with "build" (https://github.com/pypa/build), but this is easily circumvented with this simple setup.py
	@( \
		${ECHO} "from setuptools import setup" && \
		${ECHO} "setup()" \
	) > ${WRKSRC}/setup.py

.include <bsd.port.mk>

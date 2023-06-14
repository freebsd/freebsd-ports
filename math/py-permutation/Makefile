PORTNAME=	permutation
DISTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Permutations of finitely many positive integers
WWW=		https://github.com/jwodder/permutation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

pre-configure: # permutation is officially built with "build" (https://github.com/pypa/build), but this is easily circumvented with this simple setup.py
	@( \
		${ECHO} "from setuptools import setup" && \
		${ECHO} "setup()" \
	) > ${WRKSRC}/setup.py

do-test: install # instructions from tox.ini
	@cd ${WRKSRC} && \
		coverage erase && \
		coverage run -m pytest --doctest-modules --pyargs permutation && \
		coverage run -m pytest test README.rst docs/index.rst && \
		coverage combine && \
		coverage report

.include <bsd.port.mk>

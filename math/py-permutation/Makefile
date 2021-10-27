PORTNAME=	permutation
DISTVERSION=	0.3.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Permutations of finitely many positive integers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

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

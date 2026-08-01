PORTNAME=	permutation
DISTVERSION=	0.5.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Permutations of finitely many positive integers
WWW=		https://github.com/jwodder/permutation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

do-test: install # instructions from tox.ini; coverage combine/report dropped because pytest on .rst doctest files collects no coverage data
	@cd ${WRKSRC} && \
		${PYTHON_CMD} -m pytest --doctest-modules --pyargs permutation && \
		${PYTHON_CMD} -m pytest test README.rst docs/index.rst

# tests as of 0.5.0: 1 passed (doctest modules), 3991 passed (test/README.rst/docs/index.rst)

.include <bsd.port.mk>

PORTNAME=	mmcif
DISTVERSION=	1.1.1
CATEGORIES=	science biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for accessing mmCIF data
WWW=		https://mmcif.wwpdb.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25:www/py-requests@${PY_FLAVOR}

USES=		bison cmake:indirect python
USE_PYTHON=	pep517 autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@${MKDIR} ${WRKDIR}/.test-run && \
		cd ${WRKDIR}/.test-run && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "from mmcif.io.IoAdapterCore import IoAdapterCore as IoAdapter"

# tests as of 1.1.1: upstream sdist contains no Python test suite; smoke import from mmcif.io.IoAdapterCore passed.

.include <bsd.port.mk>

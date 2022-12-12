PORTNAME=	wcmatch
PORTVERSION=	8.4.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Wildcard/glob file name matcher
WWW=		https://pypi.org/project/wcmatch/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.21.1:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=22.2:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bracex>=2.1.1:textproc/py-bracex@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	flavors


# PYTHON_EXT_SUFFIX could be used here, except that it is
# special-cased for python3.7 which we don't want.
PYCACHE_SUFFIX=	.cpython-${PYTHON_SUFFIX}.pyc

PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYCACHE_SUFFIX=${PYCACHE_SUFFIX}

NO_ARCH=	yes

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} -m hatchling build -t wheel

do-install:
	${PYTHON_CMD} -m pip --no-cache-dir install --no-deps --ignore-installed \
	  --disable-pip-version-check --target ${STAGEDIR}${PYTHON_SITELIBDIR} \
	  ${WRKSRC}/dist/${PORTNAME}-${PORTVERSION}-py3-none-any.whl

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>

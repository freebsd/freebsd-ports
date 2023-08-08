PORTNAME=	annoy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.3
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Approximate Nearest Neighbors algorithm
WWW=		https://github.com/spotify/annoy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail because nose is broken

USE_GITHUB=	yes
GH_ACCOUNT=	spotify

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/annoy/annoylib${PYTHON_EXT_SUFFIX}.so

do-test:
	cd ${TEST_WRKSRC} && \
		${ECHO} "saving data" && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test-save.py && \
		${ECHO} "loading data" && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test-load.py && \
		${ECHO} "tests succeeded"

.include <bsd.port.mk>

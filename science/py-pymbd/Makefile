PORTNAME=	pymbd
DISTVERSION=	0.15.0
CATEGORIES=	science # chemistry
MASTER_SITES=	https://github.com/libmbd/libmbd/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body dispersion library
WWW=		https://github.com/libmbd/libmbd

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-dynamic-versioning>0:devel/py-poetry-dynamic-versioning@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
LIB_DEPENDS=	libmbd.so:science/libmbd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.20,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6:science/py-scipy@${PY_FLAVOR}

USES=		localbase python shebangfix
USE_PYTHON=	pep517 autoplist

SHEBANG_FILES=	src/pymbd/benchmark.py

MAKE_ENV=	LIBMBD_PREFIX=${LOCALBASE}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install: # strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_libmbd.abi3.so

do-test: # also see https://github.com/libmbd/libmbd/issues/44
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>

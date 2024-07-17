PORTNAME=	libgetar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.7
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to read and write GEneric Trajectory ARchives
WWW=		https://github.com/glotzerlab/libgetar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}breathe>0:devel/py-breathe@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils cython autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gtar/_gtar${PYTHON_EXT_SUFFIX}.so

do-test:
	@cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest discover

.include <bsd.port.mk>

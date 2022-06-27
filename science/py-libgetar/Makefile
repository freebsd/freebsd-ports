PORTNAME=	libgetar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to read and write GEneric Trajectory ARchives

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}breathe>0:devel/py-breathe@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest # tests fail, see https://github.com/glotzerlab/libgetar/issues/29

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

TEST_ENV=      ${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gtar/_gtar${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

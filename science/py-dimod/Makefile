PORTNAME=	dimod
DISTVERSION=	0.11.4
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Shared API for QUBO/Ising samplers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}reno>0:textproc/py-reno@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.7+
USE_PYTHON=	distutils cython autoplist unittest # tests are broken, see https://github.com/dwavesystems/dimod/issues/1234

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name "*${PYTHON_EXT_SUFFIX}.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>

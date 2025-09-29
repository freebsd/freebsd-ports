PORTNAME=	dwave-inspector
DISTVERSION=	0.5.5
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Problem Inspector
WWW=		https://docs.ocean.dwavesys.com/projects/inspector/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.10.0:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-cloud-client>=0.13.0:science/py-dwave-cloud-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-system>=1.3.0:science/py-dwave-system@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2.2:www/py-flask@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.10.0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcrpy>0:devel/py-vcrpy@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	distutils cython unittest # few tests fail, see https://github.com/dwavesystems/dwave-inspector/issues/151

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

post-install:
	# remove conflicting __init__.py, see https://github.com/dwavesystems/dwave-system/issues/462
	@${RM} -r \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__init__.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__pycache__

.include <bsd.port.mk>

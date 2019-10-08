# $FreeBSD$

PORTNAME=	fastdtw
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Time Warping (DTW) algorithm with an O(N) complexity

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # tests are only on github
GH_ACCOUNT=	slaypni
USE_PYTHON=	distutils cython autoplist

do-test: # tests fail: https://github.com/slaypni/fastdtw/issues/23
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>

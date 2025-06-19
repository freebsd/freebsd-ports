PORTNAME=	fastdtw
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
PORTREVISION=	3
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Time Warping (DTW) algorithm with an O(N) complexity
WWW=		https://github.com/slaypni/fastdtw

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes # tests are only on github
GH_ACCOUNT=	slaypni
USE_PYTHON=	distutils cython autoplist pytest # tests fail: https://github.com/slaypni/fastdtw/issues/23

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fastdtw/_fastdtw${PYTHON_TAG}.so

.include <bsd.port.mk>

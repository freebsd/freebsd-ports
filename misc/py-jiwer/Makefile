PORTNAME=	jiwer
#DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate speech-to-text system with similarity measures
WWW=		https://github.com/jitsi/jiwer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3:devel/py-rapidfuzz@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=4.0.0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

#USE_GITHUB=	yes
#GH_ACCOUNT=	jitsi

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 3.1.0: 72 passed, 18 warnings in 635.74s (0:10:35)

.include <bsd.port.mk>

PORTNAME=	jiwer
#DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate speech-to-text system with similarity measures
WWW=		https://github.com/jitsi/jiwer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3.9.7:devel/py-rapidfuzz@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=4.0.0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

#USE_GITHUB=	yes
#GH_ACCOUNT=	jitsi

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 4.0.0: 83 passed in 49.50s

.include <bsd.port.mk>

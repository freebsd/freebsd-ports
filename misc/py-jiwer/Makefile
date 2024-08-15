PORTNAME=	jiwer
#DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.4 # see https://github.com/jitsi/jiwer/issues/91
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate speech-to-text system with similarity measures
WWW=		https://github.com/jitsi/jiwer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3:devel/py-rapidfuzz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist #pytest

#USE_GITHUB=	yes
#GH_ACCOUNT=	jitsi

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	zxcvbn
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.28
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Realistic password strength estimator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
GH_ACCOUNT=	dwolfhub
GH_PROJECT=	${PORTNAME}-python

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>

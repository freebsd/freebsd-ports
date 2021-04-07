PORTNAME=	prawcore
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Low-level communication layer for PRAW 4+

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.6.0,<3.0.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0.8:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testfixtures>4.13.2,<7:devel/py-testfixtures@${PY_FLAVOR}
# to be ported  betamax >=0.8, <0.9
#               betamax-matchers >=0.3.0, <0.5
#               betamax-serializers >=0.2, <0.3

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>

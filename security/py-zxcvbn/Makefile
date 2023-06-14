PORTNAME=	zxcvbn
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.28
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Realistic password strength estimator
WWW=		https://pypi.org/project/zxcvbn/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_ARCH=	yes
USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils pytest
GH_ACCOUNT=	dwolfhub
GH_PROJECT=	${PORTNAME}-python

.include <bsd.port.mk>

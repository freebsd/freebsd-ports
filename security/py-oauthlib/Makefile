PORTNAME=	oauthlib
PORTVERSION=	3.3.1
CATEGORIES=	security net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic, spec-compliant, thorough implementation of the OAuth request-signing logic
WWW=		https://github.com/oauthlib/oauthlib

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.6:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	RSA SIGNALS SIGNEDTOKEN
OPTIONS_DEFAULT=RSA SIGNALS SIGNEDTOKEN
RSA_DESC=		RSA support
SIGNALS_DESC=		Signal support
SIGNEDTOKEN_DESC=	Signed token support

RSA_USE=			PYTHON=cryptography
SIGNALS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}blinker>=1.4.0:devel/py-blinker@${PY_FLAVOR}
SIGNEDTOKEN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0.0<3:www/py-pyjwt@${PY_FLAVOR}
SIGNEDTOKEN_USE=		PYTHON=cryptography

.include <bsd.port.mk>

PORTNAME=	oauthlib
PORTVERSION=	3.2.0
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic, spec-compliant, thorough implementation of the OAuth request-signing logic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.6:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	RSA SIGNALS SIGNEDTOKEN
OPTIONS_DEFAULT=RSA SIGNALS SIGNEDTOKEN
RSA_DESC=		RSA support
SIGNALS_DESC=		Signal support
SIGNEDTOKEN_DESC=	Signed token support

RSA_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}cryptography>=3.0.0:security/py-cryptography@${PY_FLAVOR}
SIGNALS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}blinker>=1.4.0:devel/py-blinker@${PY_FLAVOR}
SIGNEDTOKEN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=3.0.0:security/py-cryptography@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0.0<3:www/py-pyjwt@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	pyjwt
PORTVERSION=	1.4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyJWT-${PORTVERSION}

MAINTAINER=	terje@elde.net
COMMENT=	JSON Web Token implementation in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Some tests are skipped without pycrypto, but its not
# referenced as a requirement anymore.
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto

USES=		python
USE_PYTHON=	distutils concurrent autoplist

OPTIONS_DEFINE=	RSASSA

RSASSA_DESC=		RSASSA-PKCS1 v1.5 signature support
RSASSA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -c /dev/null -v -rs

.include <bsd.port.mk>

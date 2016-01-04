# $FreeBSD$

PORTNAME=	pyjwt
PORTVERSION=	0.2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
DISTNAME=	PyJWT-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	terje@elde.net
COMMENT=	JSON Web Token implementation in Python

LICENSE=	MIT
# LICENSE_FILE=	${WRKSRC}/LICENSE

RSASSA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto

OPTIONS_DEFINE=	RSASSA
RSASSA_DESC=	RSASSA-PKCS1 v1.5 signature support

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>

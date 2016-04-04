# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oauthlib
PORTVERSION=	1.0.3
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	RFC-compliant implementation of the OAuth request-signing logic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.0.0:www/py-pyjwt \
		${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker

OPTIONS_DEFINE=		RSA SIGNALS SIGNEDTOKEN
OPTIONS_DEFAULT=	RSA SIGNALS SIGNEDTOKEN

RSA_DESC=		Enable RSA Support
SIGNALS_DESC=		Enable signal support
SIGNEDTOKEN_DESC=	Support for Signed Token

RSA_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography
SIGNALS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker
SIGNEDTOKEN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography \
				${PYTHON_PKGNAMEPREFIX}pyjwt>=1.0.0:www/py-pyjwt

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2 \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock
.endif

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>

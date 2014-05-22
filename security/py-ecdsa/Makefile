# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	ecdsa
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kyuupichan@gmail.com
COMMENT=	ECDSA cryptographic signature library (pure python)

LICENSE=	MIT

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>

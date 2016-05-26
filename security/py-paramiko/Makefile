# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	paramiko
PORTVERSION=	2.0.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python SSH2 protocol library

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	EXAMPLES

regression-test: extract
	@(cd ${WRKSRC} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>

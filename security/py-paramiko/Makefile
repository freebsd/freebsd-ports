# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	paramiko
PORTVERSION=	2.3.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python SSH2 protocol library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>0:security/py-bcrypt \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}pynacl>0:security/py-pynacl

USES?=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py??-paramiko1-*

OPTIONS_DEFINE=	EXAMPLES

do-test: extract
	@(cd ${WRKSRC} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>

# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	paramiko
PORTVERSION=	1.9.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	A python library for making SSH2 connections

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/demos && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

regression-test: build
	@(cd ${WRKSRC} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>

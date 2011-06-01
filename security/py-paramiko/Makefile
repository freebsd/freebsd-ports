# Ports collection makefile for:      paramiko
# Date created:               4 Feb   2006
# Whom:                       Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	paramiko
PORTVERSION=	1.7.7.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	A python library for making SSH2 connections

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/demos && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

regression-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>

# Ports collection makefile for:      paramiko
# Date created:               4 Feb   2006
# Whom:                       Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	paramiko
PORTVERSION=	1.7.6
CATEGORIES=	security python
MASTER_SITES=	http://www.lag.net/paramiko/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	A python library for making SSH2 connections

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/demos/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

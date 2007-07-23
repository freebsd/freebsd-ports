# Ports collection makefile for:      paramiko
# Date created:               4 Feb   2006
# Whom:                       Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	paramiko
PORTVERSION=	1.7
CATEGORIES=	security python
MASTER_SITES=	http://www.lag.net/paramiko/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	A python library for making SSH2 connections

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	2.3+
USE_PYTHON_PREFIX=	yes
USE_PYDISTUTILS=	yes
USE_ZIP=	yes

.include <bsd.port.mk>

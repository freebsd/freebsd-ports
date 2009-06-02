# New ports collection makefile for:	py-restclient
# Date created:		26 March, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	py-restclient
PORTVERSION=	1.3.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python REST Client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/httplib2/__init__.py:${PORTSDIR}/www/py-httplib2

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

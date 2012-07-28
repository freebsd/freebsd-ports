# New ports collection makefile for: py-requests
# Date created:		2011-07-30
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	requests
PORTVERSION=	0.13.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Requests is an elegant and simple HTTP library for Python

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:${PORTSDIR}/security/py-certify \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0.1.0:${PORTSDIR}/security/py-oauthlib

USE_PYTHON=	-3.1
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

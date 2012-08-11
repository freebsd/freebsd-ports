# New ports collection makefile for: py-requests
# Date created:		2011-07-30
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	requests
PORTVERSION=	0.13.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Requests is a HTTP library, written in Python, for human beings

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:${PORTSDIR}/security/py-certify \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0.1.0:${PORTSDIR}/security/py-oauthlib

USE_PYTHON=	-3.1
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

# New ports collection makefile for:	py-WebTest
# Date created:		24 Feb, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WebTest
PORTVERSION=	1.2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper to test WSGI applications

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:${PORTSDIR}/www/py-webob
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:${PORTSDIR}/www/py-webob

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

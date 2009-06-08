# New ports collection makefile for:	py-WebError
# Date created:		24 Feb, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WebError
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Web Error handling and exception catching

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.3:${PORTSDIR}/textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.8:${PORTSDIR}/devel/py-simplejson

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

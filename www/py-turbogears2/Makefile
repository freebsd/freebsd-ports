# New ports collection makefile for:	turbogears2
# Date created:		9 Aug, 2009
# Whom:			Wen Heping	<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	TurboGears2
PORTVERSION=	2.0.1
CATEGORIES=	www python
MASTER_SITES=	http://www.turbogears.org/2.0/downloads/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python-Based Framework for Rapid Web Development

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0.9.4:${PORTSDIR}/devel/py-ToscaWidgets \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.5.1:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}WebFlash>=0.1a8:${PORTSDIR}/www/py-WebFlash \
		${PYTHON_PKGNAMEPREFIX}WebError>=0.10.1:${PORTSDIR}/www/py-WebError \
		${PYTHON_PKGNAMEPREFIX}repoze.tm2>=0:${PORTSDIR}/devel/py-repoze.tm2 \
		${PYTHON_PKGNAMEPREFIX}TurboJson>=1.2.1:${PORTSDIR}/devel/py-turbojson \
		${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.0:${PORTSDIR}/devel/py-repoze.who \
		${PYTHON_PKGNAMEPREFIX}repoze.what-pylons>=1.0:${PORTSDIR}/devel/py-repoze.what-pylons

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

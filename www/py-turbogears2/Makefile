# New ports collection makefile for:	turbogears2
# Date created:		9 Aug, 2009
# Whom:			Wen Heping	<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	TurboGears2
PORTVERSION=	2.1.4
CATEGORIES=	www python
MASTER_SITES=	http://www.turbogears.org/2.1/downloads/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python-Based Framework for Rapid Web Development

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0.9.4:${PORTSDIR}/devel/py-ToscaWidgets \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.5.1:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}WebFlash>=0.1a8:${PORTSDIR}/www/py-WebFlash \
		${PYTHON_PKGNAMEPREFIX}WebError>=0.10.1:${PORTSDIR}/www/py-WebError \
		${PYTHON_PKGNAMEPREFIX}repoze.tm2>=0:${PORTSDIR}/devel/py-repoze.tm2 \
		${PYTHON_PKGNAMEPREFIX}TurboJson>=1.3.0:${PORTSDIR}/devel/py-turbojson \
		${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.0:${PORTSDIR}/devel/py-repoze.who \
		${PYTHON_PKGNAMEPREFIX}repoze.who-testutil>=1.0.8:${PORTSDIR}/devel/py-repoze.who-testutil \
		${PYTHON_PKGNAMEPREFIX}repoze.what>=1.0.8:${PORTSDIR}/devel/py-repoze.what \
		${PYTHON_PKGNAMEPREFIX}repoze.what-pylons>=1.0:${PORTSDIR}/devel/py-repoze.what-pylons \
		${PYTHON_PKGNAMEPREFIX}repoze.tm2>=1.0:${PORTSDIR}/devel/py-repoze.tm2 \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:${PORTSDIR}/devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}nose>=0:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}TurboKid>=1.0.4:${PORTSDIR}/devel/py-turbokid \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.4:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}Chameleon>=2.0:${PORTSDIR}/textproc/py-Chameleon \
		${PYTHON_PKGNAMEPREFIX}mako>=0:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.4:${PORTSDIR}/devel/py-babel

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

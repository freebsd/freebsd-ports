# New ports collection makefile for:	py-pyramid
# Date created:		                21 March 2011
# Whom:			                Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyramid
PORTVERSION=	1.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A small, fast, web development framework by the Pylons community

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Chameleon>=1.2.3:${PORTSDIR}/textproc/py-Chameleon \
		${PYTHON_PKGNAMEPREFIX}Paste>=1.7.2:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3.3:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7.3:${PORTSDIR}/www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}mako>=0.3.6:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}repoze.lru>=0:${PORTSDIR}/devel/py-repoze.lru \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.8:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}translationstring>=0:${PORTSDIR}/textproc/py-translationstring \
		${PYTHON_PKGNAMEPREFIX}venusian>=0.5:${PORTSDIR}/devel/py-venusian \
		${PYTHON_PKGNAMEPREFIX}webob>=1.0:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=0:${PORTSDIR}/devel/py-zope.deprecation \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.5.1:${PORTSDIR}/devel/py-zopeInterface \
		${PYTHON_PKGNAMEPREFIX}zopeevent>=0:${PORTSDIR}/devel/py-zopeevent
RUN_DEPENDS=	${BUILD_DEPENDS}

#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}WebTest>=1.1:${PORTSDIR}/www/py-WebTest

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>

# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyramid
PORTVERSION=	1.4.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A small, fast, web development framework by the Pylons community

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Chameleon>=1.2.3:${PORTSDIR}/textproc/py-Chameleon \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}mako>=0.3.6:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}repoze.lru>=0.4:${PORTSDIR}/devel/py-repoze.lru \
		${PYTHON_PKGNAMEPREFIX}translationstring>=0.4:${PORTSDIR}/textproc/py-translationstring \
		${PYTHON_PKGNAMEPREFIX}venusian>=1.0a6:${PORTSDIR}/devel/py-venusian \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.b3:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=3.5.0:${PORTSDIR}/devel/py-zope.deprecation \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.8.0:${PORTSDIR}/devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}WebTest>=1.1:${PORTSDIR}/www/py-WebTest \
#		${PYTHON_PKGNAMEPREFIX}zope.component>=3.6.0:${PORTSDIR}/devel/py-zope.component

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>

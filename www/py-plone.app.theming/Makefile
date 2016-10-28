# $FreeBSD$

PORTNAME=	plone.app.theming
PORTVERSION=	1.1.7
PORTEPOCH=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Integrates the Diazo theming engine with Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}diazo>=0:devel/py-diazo \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}roman>0:math/py-roman \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2.4:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=1.0:www/py-plone.app.registry \
		${PYTHON_PKGNAMEPREFIX}plone.subrequest>=0:www/py-plone.subrequest \
		${PYTHON_PKGNAMEPREFIX}plone.transformchain>=0:www/py-plone.transformchain \
		${PYTHON_PKGNAMEPREFIX}plone.resource>=1.0,1:www/py-plone.resource \
		${PYTHON_PKGNAMEPREFIX}plone.resourceeditor>0:www/py-plone.resourceeditor \
		${PYTHON_PKGNAMEPREFIX}repoze.xmliter>=0.3:devel/py-repoze.xmliter \
		${PYTHON_PKGNAMEPREFIX}five.globalrequest>=0:devel/py-five.globalrequest \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

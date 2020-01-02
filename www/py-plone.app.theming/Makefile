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

DEPRECATED=	Outdated version of plone 4.3 (legacy), uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}diazo>=0:devel/py-diazo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}roman>0:math/py-roman@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2.4:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=1.0:www/py-plone.app.registry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.subrequest>=0:www/py-plone.subrequest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.transformchain>=0:www/py-plone.transformchain@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.resource>=1.0,1:www/py-plone.resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.resourceeditor>0:www/py-plone.resourceeditor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.xmliter>=0.3:devel/py-repoze.xmliter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}five.globalrequest>=0:devel/py-five.globalrequest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

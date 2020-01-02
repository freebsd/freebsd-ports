# $FreeBSD$

PORTNAME=	plone
PORTVERSION=	4.3.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
DISTNAME=	Plone-${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone Content Management System

DEPRECATED=	Outdated version of plone 4.3 (legacy), uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFPlacefulWorkflow>=0:devel/py-Products.CMFPlacefulWorkflow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFPlone>=0:www/py-Products.CMFPlone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.caching>=0:www/py-plone.app.caching@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.dexterity>0:www/py-plone.app.dexterity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.iterate>=0:www/py-plone.app.iterate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.openid>=0:security/py-plone.app.openid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.theming>0:www/py-plone.app.theming@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wicked>=0:textproc/py-wicked@${PY_FLAVOR}

OPTIONS_DEFINE=		LDAP
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.ldap>=1.2.6:www/py-plone.app.ldap@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

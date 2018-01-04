# $FreeBSD$

PORTNAME=	plone
PORTVERSION=	4.3.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
DISTNAME=	Plone-${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone Content Management System

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFPlacefulWorkflow>=0:devel/py-Products.CMFPlacefulWorkflow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFPlone>=0:www/py-Products.CMFPlone@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.caching>=0:www/py-plone.app.caching@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.dexterity>0:www/py-plone.app.dexterity@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.iterate>=0:www/py-plone.app.iterate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.openid>=0:security/py-plone.app.openid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.theming>0:www/py-plone.app.theming@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wicked>=0:textproc/py-wicked@${FLAVOR}

OPTIONS_DEFINE=		LDAP
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.ldap>=1.2.6:www/py-plone.app.ldap@${FLAVOR}

NO_ARCH=	yes
USES=		cpe python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

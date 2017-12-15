# $FreeBSD$

PORTNAME=	plone.fieldsets
PORTVERSION=	2.0.3
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Allows to group fields into different fieldsets

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.formlib>=0:devel/py-five.formlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

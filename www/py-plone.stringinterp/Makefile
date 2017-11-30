# $FreeBSD$

PORTNAME=	plone.stringinterp
PORTVERSION=	1.0.13
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adaptable string interpolation

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

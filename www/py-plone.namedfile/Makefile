# $FreeBSD$

PORTNAME=	plone.namedfile
PORTVERSION=	3.0.8
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	File types and fields for images, files and blob files with filenames

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.copy>0:devel/py-zope.copy \
		${PYTHON_PKGNAMEPREFIX}zope.security>0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822 \
		${PYTHON_PKGNAMEPREFIX}zope.app.file>0:devel/py-zope.app.file

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

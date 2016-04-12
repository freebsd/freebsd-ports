# $FreeBSD$

PORTNAME=	plone.namedfile
PORTVERSION=	2.0.10
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	File types and fields for images, files and blob files with filenames

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.security>0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	zope.app.locales
PORTVERSION=	3.7.3
PORTREVISION=	1
CATEGORIES=	textproc python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope locale extraction and management utilities

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.app.applicationcontrol>=0:devel/py-zope.app.applicationcontrol \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=0:devel/py-zope.app.appsetup

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

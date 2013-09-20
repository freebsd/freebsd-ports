# $FreeBSD$

PORTNAME=	Products.TinyMCE
PORTVERSION=	1.2.16
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adds support for TinyMCE to Plone

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.imaging>=1.0.2:${PORTSDIR}/www/py-plone.app.imaging \
		${PYTHON_PKGNAMEPREFIX}plone.outputfilters>=0:${PORTSDIR}/www/py-plone.outputfilters \
		${PYTHON_PKGNAMEPREFIX}elementtree>=0:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_PKGNAMEPREFIX}zope.app.component>0:${PORTSDIR}/devel/py-zope.app.component \
		${PYTHON_PKGNAMEPREFIX}zope.app.content>0:${PORTSDIR}/devel/py-zope.app.content

DIST_SUBDIR=	zope
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>

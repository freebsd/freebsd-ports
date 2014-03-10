# $FreeBSD$

PORTNAME=	plone.portlet.collection
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Portlet that fetches results from a collection

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:${PORTSDIR}/www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:${PORTSDIR}/www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:${PORTSDIR}/www/py-plone.app.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.vocabularies>=0:${PORTSDIR}/www/py-plone.app.vocabularies \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:${PORTSDIR}/www/py-plone.app.form

USES=		zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>

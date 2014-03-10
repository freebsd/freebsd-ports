# $FreeBSD$

PORTNAME=	plone.formwidget.namedfile
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Image widget for z3c.form and Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:${PORTSDIR}/www/py-plone.namedfile \
		${PYTHON_PKGNAMEPREFIX}z3c.form>0:${PORTSDIR}/devel/py-z3c.form \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:${PORTSDIR}/www/py-plone.z3cform

USES=		zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>

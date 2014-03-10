# $FreeBSD$

PORTNAME=	plone.autoform
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Tools to construct z3c.form forms

LICENSE=	LGPL20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:${PORTSDIR}/devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>=1.1:${PORTSDIR}/www/py-plone.supermodel \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>=0:${PORTSDIR}/www/py-plone.z3cform \
		${PYTHON_PKGNAMEPREFIX}z3c.form>=0:${PORTSDIR}/devel/py-z3c.form

USES=		zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>

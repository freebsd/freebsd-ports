# $FreeBSD$

PORTNAME=	plone.dexterity
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Flexible CMF content

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.alterego>0:${PORTSDIR}/www/py-plone.alterego \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>0:${PORTSDIR}/www/py-plone.autoform \
		${PYTHON_PKGNAMEPREFIX}plone.behavior>0:${PORTSDIR}/www/py-plone.behavior \
		${PYTHON_PKGNAMEPREFIX}plone.folder>0:${PORTSDIR}/www/py-plone.folder \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>0:${PORTSDIR}/www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:${PORTSDIR}/www/py-plone.rfc822 \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>0:${PORTSDIR}/www/py-plone.supermodel \
		${PYTHON_PKGNAMEPREFIX}plone.synchronize>0:${PORTSDIR}/www/py-plone.synchronize \
		${PYTHON_PKGNAMEPREFIX}plone.uuid>0:${PORTSDIR}/www/py-plone.uuid \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:${PORTSDIR}/www/py-plone.z3cform \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>0:${PORTSDIR}/devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>0:${PORTSDIR}/devel/py-Products.CMFDynamicViewFTI \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>0:${PORTSDIR}/devel/py-Products.statusmessages \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>0:${PORTSDIR}/devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.browser>0:${PORTSDIR}/devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.container>0:${PORTSDIR}/devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>0:${PORTSDIR}/devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>0:${PORTSDIR}/devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>0:${PORTSDIR}/devel/py-zope.filerepresentation \
		${PYTHON_PKGNAMEPREFIX}zope.size>0:${PORTSDIR}/devel/py-zope.size \
		zodb${PYTHON_PKGNAMESUFFIX}>0:${PORTSDIR}/databases/zodb3

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USES=			zope zip

.include <bsd.port.mk>

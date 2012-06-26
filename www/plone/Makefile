# New ports collection makefile for:	plone
# Date created:				25 April 2012
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	plone
PORTVERSION=	4.1.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
DISTNAME=	Plone-${PORTVERSION}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	The Plone Content Management System

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFPlacefulWorkflow>=0:${PORTSDIR}/devel/py-Products.CMFPlacefulWorkflow \
		${PYTHON_PKGNAMEPREFIX}Products.CMFPlone>=0:${PORTSDIR}/www/py-Products.CMFPlone \
		${PYTHON_PKGNAMEPREFIX}Products.kupu>=0:${PORTSDIR}/www/py-Products.kupu \
		${PYTHON_PKGNAMEPREFIX}plone.app.caching>=0:${PORTSDIR}/www/py-plone.app.caching \
		${PYTHON_PKGNAMEPREFIX}plone.app.iterate>=0:${PORTSDIR}/www/py-plone.app.iterate \
		${PYTHON_PKGNAMEPREFIX}plone.app.openid>=0:${PORTSDIR}/security/py-plone.app.openid \
		${PYTHON_PKGNAMEPREFIX}wicked>=0:${PORTSDIR}/textproc/py-wicked

OPTIONS_DEFINE=	LDAP
OPTIONS_EXCLUDE=NLS DOCS

DIST_SUBDIR=	zope
PYDISTUTILS_PKGNAME=	Plone
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}plone.app.ldap>=1.2.6:${PORTSDIR}/www/py-plone.app.ldap
.endif

.include <bsd.port.mk>

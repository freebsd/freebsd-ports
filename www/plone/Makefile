# $FreeBSD$

PORTNAME=	plone
PORTVERSION=	4.3.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
DISTNAME=	Plone-${PORTVERSION}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone Content Management System

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFPlacefulWorkflow>=0:${PORTSDIR}/devel/py-Products.CMFPlacefulWorkflow \
		${PYTHON_PKGNAMEPREFIX}Products.CMFPlone>=0:${PORTSDIR}/www/py-Products.CMFPlone \
		${PYTHON_PKGNAMEPREFIX}plone.app.caching>=0:${PORTSDIR}/www/py-plone.app.caching \
		${PYTHON_PKGNAMEPREFIX}plone.app.dexterity>0:${PORTSDIR}/www/py-plone.app.dexterity \
		${PYTHON_PKGNAMEPREFIX}plone.app.iterate>=0:${PORTSDIR}/www/py-plone.app.iterate \
		${PYTHON_PKGNAMEPREFIX}plone.app.openid>=0:${PORTSDIR}/security/py-plone.app.openid \
		${PYTHON_PKGNAMEPREFIX}plone.app.theming>0:${PORTSDIR}/www/py-plone.app.theming \
		${PYTHON_PKGNAMEPREFIX}wicked>=0:${PORTSDIR}/textproc/py-wicked

OPTIONS_DEFINE=	LDAP
OPTIONS_EXCLUDE=NLS DOCS

DIST_SUBDIR=	zope
PYDISTUTILS_PKGNAME=	Plone
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}plone.app.ldap>=1.2.6:${PORTSDIR}/www/py-plone.app.ldap
.endif

.include <bsd.port.mk>

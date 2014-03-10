# $FreeBSD$

PORTNAME=	plone.app.theming
PORTVERSION=	1.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Integrates the Diazo theming engine with Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}diazo>=0:${PORTSDIR}/devel/py-diazo \
		${PYTHON_PKGNAMEPREFIX}docutils>0:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}roman>0:${PORTSDIR}/math/py-roman \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2.4:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=1.0:${PORTSDIR}/www/py-plone.app.registry \
		${PYTHON_PKGNAMEPREFIX}plone.subrequest>=0:${PORTSDIR}/www/py-plone.subrequest \
		${PYTHON_PKGNAMEPREFIX}plone.transformchain>=0:${PORTSDIR}/www/py-plone.transformchain \
		${PYTHON_PKGNAMEPREFIX}plone.resource>=1.0:${PORTSDIR}/www/py-plone.resource \
		${PYTHON_PKGNAMEPREFIX}plone.resourceeditor>0:${PORTSDIR}/www/py-plone.resourceeditor \
		${PYTHON_PKGNAMEPREFIX}repoze.xmliter>=0.3:${PORTSDIR}/devel/py-repoze.xmliter \
		${PYTHON_PKGNAMEPREFIX}five.globalrequest>=0:${PORTSDIR}/devel/py-five.globalrequest \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:${PORTSDIR}/devel/py-zope.traversing

USES=		zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>

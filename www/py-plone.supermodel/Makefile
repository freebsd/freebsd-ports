# $FreeBSD$

PORTNAME=	plone.supermodel
PORTVERSION=	1.1.4
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Serialize Zope schema definitions to and from XML

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:${PORTSDIR}/devel/py-zope.deferredimport \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:${PORTSDIR}/devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}z3c.zcmlhook>=0:${PORTSDIR}/devel/py-z3c.zcmlhook \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -delete

.include <bsd.port.mk>

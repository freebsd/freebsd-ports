# $FreeBSD$

PORTNAME=	plone.scale
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Image scaling

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:${PORTSDIR}/devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:${PORTSDIR}/devel/py-Persistence

DIST_SUBDIR=	zope
PLIST_FILES+=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>

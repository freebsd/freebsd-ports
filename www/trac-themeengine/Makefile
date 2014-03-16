# $FreeBSD$

PORTNAME=	themeengine
PORTVERSION=	2.1.3
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to simplify distributing and deploying themes and styles

LICENSE=	BSD3CLAUSE

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USES=		tar:bzip2
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracThemeEngine
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	themeengine
PORTVERSION=	2.1.3
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to simplify distributing and deploying themes and styles

LICENSE=	BSD

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_BZIP2=	yes
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracThemeEngine
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>

# Created by: Brooks Davis <brooks@freebsd.org>
# $FreeBSD$

PORTNAME=	themeengine
PORTVERSION=	2.1.0
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Plugin to simplify distributing and deploying themes and styles

LICENSE=	BSD

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_BZIP2=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracThemeEngine
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>

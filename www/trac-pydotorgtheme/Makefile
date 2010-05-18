# New ports collection makefile for: trac-pydotorgtheme
# Date created:                      January 9, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;:L}
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-

MAINTAINER=	brooks@freebsd.org
COMMENT=	This is a theme that emulates the look of python.org

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		trac-themeengine>=2.0:${PORTSDIR}/www/trac-themeengine
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.5+
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TracPyDotOrgTheme
WRKSRC=		${WRKDIR}/${PORTNAME}
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-build:
	@${DO_NADA}

.include <bsd.port.mk>

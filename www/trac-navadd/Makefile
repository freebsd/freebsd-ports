# New ports collection makefile for: trac-navadd
# Date created:                      January 23, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;:L}
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	brooks@freebsd.org
COMMENT=	A plugin for adding navigation items into Trac navigation bars

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	NavAdd
WRKSRC=		${WRKDIR}/${PORTNAME}plugin
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-build:
	@${DO_NADA}

.include <bsd.port.mk>

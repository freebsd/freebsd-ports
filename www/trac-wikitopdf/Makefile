# New ports collection makefile for: trac-wikitopdf
# Date created:                      January 9, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;S;Plugin$;;:L}
PORTVERSION=	2.2.2
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	brooks@freebsd.org
COMMENT=	Plugin to generate PDF documents from the Wiki

RUN_DEPENDS+=	htmldoc:${PORTSDIR}/textproc/htmldoc \
		tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TracWikiToPdfPlugin
WRKSRC=		${WRKDIR}/${PORTNAME}plugin
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-build:
	@${DO_NADA}

.include <bsd.port.mk>

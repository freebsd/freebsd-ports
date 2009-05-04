# New ports collection makefile for: trac-wikitemplates
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	wikitemplates
PORTVERSION=	0.3.0p3
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION:S/p/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Templates for the Trac wiki

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracCtxtnavAdd-1.1_r1-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-ctxtnavadd

BROKEN=		bad depobj

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracWikiTemplates
PYDISTUTILS_PKGVERSION=	${PORTVERSION:S/p/rc/}

.include <bsd.port.mk>

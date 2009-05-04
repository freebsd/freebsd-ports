# New ports collection makefile for: trac-wikinotification
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	wikinotificationplugin
PORTVERSION=	0.1.0p4
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allow email notifications on wiki page changes

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracCtxtnavAdd-1.1_r1-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-ctxtnavadd

BROKEN=		bad depobj

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	2.3+
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	TracWikiNotification
PYDISTUTILS_PKGVERSION=	${PORTVERSION:S/p/rc/}

.include <bsd.port.mk>

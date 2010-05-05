# New ports collection makefile for: trac-wikirename
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	wikirename
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Renames Wiki pages

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracCtxtnavAdd-2.0-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-ctxtnavadd

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracWikiRename

.include <bsd.port.mk>

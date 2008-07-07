# New ports collection makefile for: trac-wikirename
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	wikirename
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Renames Wiki pages

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracCtxtnavAdd-1.1_r1-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-ctxtnavadd \
		${PYTHON_SITELIBDIR}/TracWebAdmin-0.1.2dev-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-webadmin

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracWikiRename

.include <bsd.port.mk>

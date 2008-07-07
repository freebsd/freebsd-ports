# New ports collection makefile for: trac-blog
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	blog
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	trac${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A blog plugin for Trac

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracTags-0.4.1-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-tags \
		${PYTHON_SITELIBDIR}/TracWebAdmin-0.1.2dev-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-webadmin

WRKSRC=		${WRKDIR}/trac${PORTNAME}plugin
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	tBlog
PYDISTUTILS_PKGVERSION=	${PORTVERSION}dev

.include <bsd.port.mk>

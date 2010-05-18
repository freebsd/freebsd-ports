# New ports collection makefile for: trac-customroadmap
# Date created:                      Oct 08 2008
# Whom:                              Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	customroadmap
PORTVERSION=	0.4.2348
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://people.freebsd.org/~mm/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Custom roadmap plugin for trac

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracCustomRoadmap
PYDISTUTILS_PKGVERSION=	0.4

PLIST_SUB+=	PORTVERSION=${PYDISTUTILS_PKGVERSION} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>

# New ports collection makefile for: trac-customroadmap
# Date created:                      Oct 08 2008
# Whom:                              Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	advancedticketworkflow
PORTVERSION=	0.10.3940
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://people.freebsd.org/~mm/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Advanced Ticket Workflow Plugin for Trac

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	AdvancedTicketWorkflowPlugin
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}dev

PLIST_SUB+=	PORTVERSION=${PORTVERSION:R}dev PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>

# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	keywordsecretticket
PORTVERSION=	1.0.1.${GITDATE}
CATEGORIES=	www devel python
MASTER_SITES=	https://github.com/KKBOX/trac-keyword-secret-ticket-plugin/tarball/${GITVERSION}/
PKGNAMEPREFIX=	trac-
DISTNAME=	KKBOX-trac-keywordsecretticket-plugin-98edea2

MAINTAINER=	gaod@hychen.org
COMMENT=	Ticket security policy based on keyword for Trac

LICENSE=	BSD3CLAUSE

GITVERSION=	98edea2
GITDATE=	20130401
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/KKBOX-trac-keyword-secret-ticket-plugin-${GITVERSION}

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

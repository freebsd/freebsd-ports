# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	keywordsecretticket
PORTVERSION=	1.0.1.${GITDATE}
CATEGORIES=	www devel python
PKGNAMEPREFIX=	trac-

MAINTAINER=	gaod@hychen.org
COMMENT=	Ticket security policy based on keyword for Trac

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	KKBOX
GH_PROJECT=	trac-keyword-secret-ticket-plugin
GH_TAGNAME=	98edea2
GITDATE=	20130401

RUN_DEPENDS+=	tracd:www/trac

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	keywordsecretticket
PORTVERSION=	1.0.1.${GITDATE}
PORTREVISION=	1
CATEGORIES=	www devel python
PKGNAMEPREFIX=	trac-

MAINTAINER=	gaod@hychen.org
COMMENT=	Ticket security policy based on keyword for Trac

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

USE_GITHUB=	yes
GH_ACCOUNT=	KKBOX
GH_PROJECT=	trac-keyword-secret-ticket-plugin
GH_TAGNAME=	98edea2
GITDATE=	20130401

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

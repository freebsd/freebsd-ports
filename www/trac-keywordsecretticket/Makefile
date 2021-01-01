# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	keywordsecretticket
PORTVERSION=	1.0.2
CATEGORIES=	www devel python
PKGNAMEPREFIX=	trac-

MAINTAINER=	gaod@hychen.org
COMMENT=	Ticket security policy based on keyword for Trac

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

USES=		python:2.7

USE_GITHUB=	yes
GH_ACCOUNT=	trac-hacks
GH_PROJECT=	trac-keyword-secret-ticket-plugin

USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

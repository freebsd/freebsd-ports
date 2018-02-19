# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	subtickets
PORTVERSION=	0.2.0.${GITDATE}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/
PKGNAMEPREFIX=	trac-

MAINTAINER=	gaod@hychen.org
COMMENT=	Offers sub-ticket feature for managing tickets

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	tracd:www/trac

USE_GITHUB=	yes
GH_ACCOUNT=	itota
GH_PROJECT=	trac-subtickets-plugin
GH_TAGNAME=	a0fc153
GITDATE=	20130328

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

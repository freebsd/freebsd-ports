# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	subtickets
PORTVERSION=	0.2.0.${GITDATE}
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/
PKGNAMEPREFIX=	trac-
# Should not be setting DISTNAME, USE_GITHUB already sets a very nice and unique distname.
DISTNAME=	itota-trac-subtickets-plugin-a0fc153

MAINTAINER=	gaod@hychen.org
COMMENT=	Offers sub-ticket feature for managing tickets

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	tracd:www/trac

USE_GITHUB=	yes
GH_ACCOUNT=	itota
GH_PROJECT=	trac-subtickets-plugin
GH_TAGNAME=	a0fc153
GITDATE=	20130328

USES=		python:2
USE_PYTHON=	distutils autoplist

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>

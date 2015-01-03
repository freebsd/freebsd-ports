# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	subtickets
PORTVERSION=	0.2.0.${GITDATE}
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/ \
		https://github.com/itota/trac-subtickets-plugin/tarball/${GITVERSION}/
PKGNAMEPREFIX=	trac-
DISTNAME=	itota-trac-subtickets-plugin-a0fc153

MAINTAINER=	gaod@hychen.org
COMMENT=	Offers sub-ticket feature for managing tickets

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

GITVERSION=	a0fc153
GITDATE=	20130328

WRKSRC=		${WRKDIR}/itota-trac-${PORTNAME}-plugin-${GITVERSION}
USES=		python:2
USE_PYTHON=	distutils autoplist

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>

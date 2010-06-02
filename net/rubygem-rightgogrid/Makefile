# Ports collection makefile for:	rubygem-rightgogrid
# Date created:			23 Apr 2008
# Whom:				Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rightgogrid
PORTVERSION=	0.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
DISTNAME=	right_gogrid-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Provides Ruby access to the GoGrid API

RUN_DEPENDS=	rubygem-righthttpconnection>=1.2.4:${PORTSDIR}/net/rubygem-righthttpconnection

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
UNIQUENAME=	${PORTNAME}

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	libevnet
# Date created:			Apr 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libevnet
PORTVERSION=	0.3.7
CATEGORIES=	net
MASTER_SITES=	http://www.25thandclement.com/~william/projects/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Network Daemon Services for libevent

BUILD_DEPENDS=	${LOCALBASE}/lib/libarena.a:${PORTSDIR}/devel/libarena
LIB_DEPENDS=	event-1.3b.1:${PORTSDIR}/devel/libevent \
		cares.1:${PORTSDIR}/dns/c-ares
RUN_DEPENDS=	${LOCALBASE}/lib/libarena.a:${PORTSDIR}/devel/libarena

USE_GMAKE=	yes

.include <bsd.port.mk>

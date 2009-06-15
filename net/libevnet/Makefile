# ex:ts=8
# Ports collection makefile for:	libevnet
# Date created:			Apr 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libevnet
PORTVERSION=	0.3.8
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.25thandclement.com/~william/projects/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Network Daemon Services for libevent

BUILD_DEPENDS=	${LOCALBASE}/lib/libarena.a:${PORTSDIR}/devel/libarena
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent \
		cares.2:${PORTSDIR}/dns/c-ares
RUN_DEPENDS=	${LOCALBASE}/lib/libarena.a:${PORTSDIR}/devel/libarena

USE_OPENSSL=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>

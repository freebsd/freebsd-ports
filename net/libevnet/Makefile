# ex:ts=8
# Ports collection makefile for:	libevnet
# Date created:			Apr 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libevnet
PORTVERSION=	0.3.11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.25thandclement.com/~william/projects/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pusateri@bangj.com
COMMENT=	Network Daemon Services for libevent

BUILD_DEPENDS=	${LOCALBASE}/lib/libarena.a:${PORTSDIR}/devel/libarena
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent \
		cares.2:${PORTSDIR}/dns/c-ares
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_OPENSSL=	yes
USE_GMAKE=	yes

CPPFLAGS=	-I${LOCALBASE}/include \
		-DUSE_OPENSSL -DUSE_CARES -DUSE_IPV6 -DUSE_PTHREADS \
		-DHAVE_STRLCPY -DHAVE_STRLCAT -D_REENTRANT

MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include <bsd.port.mk>

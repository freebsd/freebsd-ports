# New ports collection makefile for:	spybye
# Date created:				23 May 2008
# Whom:					pauls
#
# $FreeBSD$
#

PORTNAME=	spybye
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	security www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A web proxy to detect malware

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

OPTIONS=	CLAMAV "Enable CLAMAV support" off

USE_RC_SUBR=	spybye
GNU_CONFIGURE=	yes

MAN1=		spybye.1

.include <bsd.port.pre.mk>

.if defined(WITH_CLAMAV)
LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav
CONFIGURE_ARGS+=	--with-libclamav=${PREFIX}/bin
.endif

.include <bsd.port.post.mk>

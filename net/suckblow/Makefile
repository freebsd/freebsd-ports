PORTNAME=	suckblow
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/archie

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Two companion utilities for transferring data over a TCP socket

USES=		uidfix
CONFLICTS=	suck-4.* suck-cnews-4.*

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>

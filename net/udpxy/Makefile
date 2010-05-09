# New ports collection makefile for:	net/udpxy
# Date created:				2 January 2009
# Whom:					Alex Deiter <Alex.Deiter@Gmail.COM>
#
# $FreeBSD$
#

PORTNAME=	udpxy
PORTVERSION=	1.0.16
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${RELEASE_MASCOT}-${PORTVERSION:R}
DISTNAME=	${PORTNAME}.${PORTVERSION:R}-${RELEASE_MASCOT}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	UDP-to-HTTP multicast traffic relay daemon

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}-${RELEASE_MASCOT}-${PORTVERSION:E}
USE_RC_SUBR=	udpxy
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
RELEASE_MASCOT=	Chipmunk
OPTIONS=	RELEASE "No asserts, no debug symbols, verbose mode on"	on \
		LEAN "No asserts, no debug symbols, verbose mode off" off \
		DEBUG "Asserts, debug symbols, verbose mode on" off

PLIST_FILES=	sbin/udpxy \
		sbin/udpxrec

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/udpxy ${PREFIX}/sbin/
	@${LN} -s udpxy ${PREFIX}/sbin/udpxrec

.include <bsd.port.pre.mk>

.if defined(WITH_RELEASE) && defined(WITHOUT_LEAN) && defined(WITHOUT_DEBUG)
ALL_TARGET=release
.elif defined(WITH_LEAN) && defined(WITHOUT_RELEASE) && defined(WITHOUT_DEBUG)
ALL_TARGET=lean
.elif defined(WITH_DEBUG) && defined(WITHOUT_RELEASE) && defined(WITHOUT_LEAN)
ALL_TARGET=debug
WITH_DEBUG=yes
.else
IGNORE=please run 'make config' again and select one build option
.endif

.include <bsd.port.post.mk>

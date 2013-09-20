# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	udpxy
PORTVERSION=	1.0.23
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${RELEASE_MASCOT}-${PORTVERSION:R}
DISTNAME=	${PORTNAME}.${PORTVERSION}-0-prod

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	UDP-to-HTTP multicast traffic relay daemon

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-0
USE_RC_SUBR=	udpxy
USE_GMAKE=	yes
RELEASE_MASCOT=	Chipmunk

OPTIONS_SINGLE=	CONF
OPTIONS_SINGLE_CONF=	RELEASE LEAN DEBUG
RELEASE_DESC=	No asserts, no debug symbols, verbose on
LEAN_DESC=	No asserts, no debug symbols, verbose off
DEBUG_DESC=	Asserts, debug symbols, verbose on
OPTIONS_DEFAULT=	RELEASE

PLIST_FILES=	sbin/udpxy \
		sbin/udpxrec

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/udpxy ${PREFIX}/sbin/
	@${LN} -s udpxy ${PREFIX}/sbin/udpxrec

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRELEASE}
ALL_TARGET=release
.elif ${PORT_OPTIONS:MLEAN}
ALL_TARGET=lean
.elif ${PORT_OPTIONS:MDEBUG}
ALL_TARGET=debug
WITH_DEBUG=yes
.endif

.include <bsd.port.mk>

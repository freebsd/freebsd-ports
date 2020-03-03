# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	udpxy
DISTVERSION=	1.0-24.1
CATEGORIES=	net

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	UDP-to-HTTP multicast traffic relay daemon

LICENSE=	GPLv3

USES=		gmake
USE_RC_SUBR=	udpxy

USE_GITHUB=	yes
GH_ACCOUNT=	pcherenkov
WRKSRC_SUBDIR=	chipmunk

OPTIONS_SINGLE=	CONF
OPTIONS_SINGLE_CONF=	RELEASE LEAN
RELEASE_DESC=	No asserts, no debug symbols, verbose on
LEAN_DESC=	No asserts, no debug symbols, verbose off
OPTIONS_DEFAULT=	RELEASE

PLIST_FILES=	sbin/udpxy \
		sbin/udpxrec \
		man/man1/udpxy.1.gz \
		man/man1/udpxrec.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/udpxy ${STAGEDIR}${PREFIX}/sbin
	${LN} -s udpxy ${STAGEDIR}${PREFIX}/sbin/udpxrec

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/en/udpxy.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/en/udpxrec.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
ALL_TARGET=debug
.elif ${PORT_OPTIONS:MRELEASE}
ALL_TARGET=release
.elif ${PORT_OPTIONS:MLEAN}
ALL_TARGET=lean
.endif

.include <bsd.port.mk>

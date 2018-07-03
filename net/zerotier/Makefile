# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	zerotier
DISTVERSION=	1.2.10
CATEGORIES=	net

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Network virtualization everywhere

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL-3

BROKEN_armv6=		fails to link: Source object ext/arm32-neon-salsa2012-asm/salsa2012.o has EABI version 0, but target zerotier-one has EABI version 5
BROKEN_armv7=		fails to link: Source object ext/arm32-neon-salsa2012-asm/salsa2012.o has EABI version 0, but target zerotier-one has EABI version 5
BROKEN_powerpc64=	fails to compile: clang: not found

USES=		gmake compiler:c11
USE_RC_SUBR=	zerotier

USE_GITHUB=	yes
GH_PROJECT=	ZeroTierOne

CFLAGS+=	-flax-vector-conversions

OPTIONS_DEFINE=	DBG
DBG_DESC=	Enable foreground debugging for zerotier-one daemon
DBG_ALL_TARGET=	debug

PLIST_FILES=	bin/zerotier-cli bin/zerotier-idtool sbin/zerotier-one

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD"
# log output via syslog when daemon(8) supports it
.if ((${OSVERSION} >= 1100513 && ${OSVERSION} < 1200000) || ${OSVERSION} >= 1200015)
SUB_LIST+=	ZEROTIER_SYSLOG="-s debug -T zerotier"
.else
SUB_LIST+=	ZEROTIER_SYSLOG=""
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zerotier-one ${STAGEDIR}${PREFIX}/sbin/
.for l in zerotier-cli zerotier-idtool
	${RLN} ${STAGEDIR}${PREFIX}/sbin/zerotier-one ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

.include <bsd.port.post.mk>

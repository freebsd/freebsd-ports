# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	zerotier
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Network virtualization everywhere

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL-3

BROKEN_armv6=		fails to link: Source object ext/arm32-neon-salsa2012-asm/salsa2012.o has EABI version 0, but target zerotier-one has EABI version 5
BROKEN_powerpc64=	fails to compile: clang: not found

USES=		gmake compiler:c11
USE_RC_SUBR=	zerotier

USE_GITHUB=	yes
GH_PROJECT=	ZeroTierOne

CFLAGS+=	-flax-vector-conversions

PLIST_FILES=	bin/zerotier-cli bin/zerotier-idtool sbin/zerotier-one

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zerotier-one ${STAGEDIR}${PREFIX}/sbin/
.for l in zerotier-cli zerotier-idtool
	${LN} -sf ../sbin/zerotier-one ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

.include <bsd.port.mk>

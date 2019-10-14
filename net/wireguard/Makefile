# $FreeBSD$

PORTNAME=	wireguard
PORTVERSION=	0.0.20191012
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/WireGuard/snapshot/
DISTNAME=	WireGuard-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Fast, modern and secure VPN Tunnel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		wireguard-go:net/wireguard-go

USES=		gmake tar:xz
USE_RC_SUBR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/src/tools

ALL_TARGET=
MAKE_ARGS=	WITH_WGQUICK=yes WITH_BASHCOMPLETION=yes
MAKE_ENV+=	MANDIR="${MANPREFIX}/man" \
		SYSCONFDIR="${PREFIX}/etc"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/completion/wg-quick.bash-completion \
		${WRKSRC}/wg-quick/freebsd.bash

.include <bsd.port.mk>

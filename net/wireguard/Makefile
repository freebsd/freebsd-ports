# $FreeBSD$

PORTNAME=	wireguard
PORTVERSION=	1.0.20210223
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-tools/snapshot/
DISTNAME=	wireguard-tools-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Fast, modern and secure VPN Tunnel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING

USES=		gmake tar:xz
USE_RC_SUBR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKE_ARGS+=	WITH_SYSTEMDUNITS=no DEBUG=no
MAKE_ENV+=	MANDIR="${MANPREFIX}/man" \
		SYSCONFDIR="${PREFIX}/etc"

OPTIONS_DEFINE=	BASHCOMPLETION WGQUICK
OPTIONS_DEFAULT=BASHCOMPLETION WGQUICK
OPTIONS_SUB=	yes

BASHCOMPLETION_DESC=		Command completion files for Bash shell
BASHCOMPLETION_RUN_DEPENDS=	bash:shells/bash
BASHCOMPLETION_MAKE_ARGS=	WITH_BASHCOMPLETION=yes
BASHCOMPLETION_MAKE_ARGS_OFF=	WITH_BASHCOMPLETION=no

WGQUICK_DESC=		wg-quick(8) userland utility
WGQUICK_RUN_DEPENDS=	bash:shells/bash \
			wireguard-go:net/wireguard-go
WGQUICK_MAKE_ARGS=	WITH_WGQUICK=yes
WGQUICK_MAKE_ARGS_OFF=	WITH_WGQUICK=no

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/completion/wg-quick.bash-completion \
		${WRKSRC}/wg-quick/freebsd.bash

.include <bsd.port.mk>

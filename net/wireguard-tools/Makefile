# $FreeBSD$

PORTNAME=	wireguard-tools
PORTVERSION=	1.0.20210315
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-tools/snapshot/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Fast, modern and secure VPN Tunnel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING

FLAVORS=	default lite
lite_PKGNAMESUFFIX=	-lite

USES=		gmake tar:xz

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKE_ARGS+=	DEBUG=no WITH_BASHCOMPLETION=yes WITH_SYSTEMDUNITS=no
MAKE_ENV+=	MANDIR="${MANPREFIX}/man" \
		SYSCONFDIR="${PREFIX}/etc"

OPTIONS_DEFINE=	WGQUICK
OPTIONS_DEFAULT=WGQUICK
OPTIONS_SUB=	yes

WGQUICK_DESC=		wg-quick(8) userland utility
WGQUICK_RUN_DEPENDS=	bash:shells/bash
WGQUICK_MAKE_ARGS=	WITH_WGQUICK=yes
WGQUICK_MAKE_ARGS_OFF=	WITH_WGQUICK=no

.if ${FLAVOR:U} == lite
USE_RC_SUBR=	wireguard_lite
OPTIONS_EXCLUDE=WGQUICK
COMMENT+=	(lite flavor)
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWGQUICK}
USE_RC_SUBR=	wireguard_wgquick
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/completion/wg-quick.bash-completion \
		${WRKSRC}/wg-quick/freebsd.bash

.include <bsd.port.mk>

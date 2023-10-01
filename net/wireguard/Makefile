PORTNAME=	wireguard
PORTVERSION=	2
PORTEPOCH=	1
CATEGORIES=	net net-vpn

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Meta-port for Wireguard
WWW=		https://www.wireguard.com

RUN_DEPENDS=	wg-quick:net/wireguard-tools \
		${KMODDIR}/if_wg.ko:net/wireguard-kmod

DEPRECATED=	Only useful for FreeBSD 12 which is EoL soon
EXPIRATION_DATE=	2023-12-31

USES=	metaport

.include <bsd.port.mk>

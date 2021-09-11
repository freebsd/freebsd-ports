PORTNAME=	wireguard
PORTVERSION=	2
PORTEPOCH=	1
CATEGORIES=	net net-vpn

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Meta-port for Wireguard

RUN_DEPENDS=	wg-quick:net/wireguard-tools

USES=	metaport

RUN_DEPENDS+=	${KMODDIR}/if_wg.ko:net/wireguard-kmod

.include <bsd.port.mk>

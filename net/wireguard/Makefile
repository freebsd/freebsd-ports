# $FreeBSD$

PORTNAME=	wireguard
PORTVERSION=	2
PORTEPOCH=	1
CATEGORIES=	net net-vpn

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Meta-port for Wireguard

RUN_DEPENDS=	wg-quick:net/wireguard-tools

USES=	metaport

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1201000
RUN_DEPENDS+=	wireguard-go:net/wireguard-go
.else
RUN_DEPENDS+=	${KMODDIR}/if_wg.ko:net/wireguard-kmod
.endif

.include <bsd.port.mk>

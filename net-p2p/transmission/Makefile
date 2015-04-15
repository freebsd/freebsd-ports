# $FreeBSD$

PORTNAME=	transmission
PORTVERSION=	2.84
CATEGORIES=	net-p2p

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Meta-port for Transmission BitTorrent client

RUN_DEPENDS=	transmission-cli:${PORTSDIR}/net-p2p/transmission-cli \
		transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon \
		transmission-gtk:${PORTSDIR}/net-p2p/transmission-gtk

CONFLICTS_INSTALL=	${PORTNAME}${PKGNAMESUFFIX}-2.[56]*

USES=	metaport

.include <bsd.port.mk>

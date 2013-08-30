# $FreeBSD$

PORTNAME=	transmission
PORTVERSION=	2.82
CATEGORIES=	net-p2p
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Meta-port for Transmission BitTorrent client

RUN_DEPENDS=	transmission-cli:${PORTSDIR}/net-p2p/transmission-cli \
		transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon \
		transmission-gtk:${PORTSDIR}/net-p2p/transmission-gtk

CONFLICTS_INSTALL=      ${PORTNAME}${PKGNAMESUFFIX}-2.[56]*

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>

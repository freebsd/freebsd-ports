# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	2.61
CATEGORIES=	net-p2p
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	crees@FreeBSD.org
COMMENT=	The "meta-port" for Transmission BitTorrent client

RUN_DEPENDS=	transmission-cli:${PORTSDIR}/net-p2p/transmission-cli \
		transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon \
		transmission-gtk:${PORTSDIR}/net-p2p/transmission-gtk2

CONFLICTS_INSTALL=      ${PORTNAME}${PKGNAMESUFFIX}-2.6*

BROKEN=		Depends on GTK 2.0 frontend; use net-p2p/transmission25 for now

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>

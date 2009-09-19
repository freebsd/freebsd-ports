# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	1.75
CATEGORIES=	net-p2p
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	The "meta-port" for Transmission BitTorrent client

RUN_DEPENDS=	transmissioncli:${PORTSDIR}/net-p2p/transmission-cli \
		transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon \
		transmission:${PORTSDIR}/net-p2p/transmission-gtk2

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>

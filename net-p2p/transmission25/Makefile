# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	2.51
CATEGORIES=	net-p2p
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	crees@FreeBSD.org
COMMENT=	The last version of Transmission that supports GTK 2.0

RUN_DEPENDS=	transmission-cli:${PORTSDIR}/net-p2p/transmission25-cli \
		transmission-daemon:${PORTSDIR}/net-p2p/transmission25-daemon \
		transmission-gtk:${PORTSDIR}/net-p2p/transmission25-gtk2

LATEST_LINK=	${PORTNAME}25${PKGNAMESUFFIX}
CONFLICTS_INSTALL=	${PORTNAME}${PKGNAMESUFFIX}-2.6*

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>

# New ports collection makefile for:	nstreams
# Date created:		22 September 1999
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	nstreams
PORTVERSION=	1.0.4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.hsc.fr/ressources/outils/nstreams/download/ \
		http://falafel.200ok.org/distfiles/nstreams/

MAINTAINER=	ecu@ipv42.net
COMMENT=	Analyses network traffic and produces ipfw rules to allow it

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

MAN1=		nstreams.1

PLIST_FILES=	bin/nstreams \
		etc/nstreams-networks.sample \
		etc/nstreams-services

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nstreams ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nstreams.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/docs/nstreams-networks \
	${PREFIX}/etc/nstreams-networks.sample
	${INSTALL_DATA} ${WRKSRC}/docs/nstreams-services ${PREFIX}/etc/nstreams-services

.include <bsd.port.mk>

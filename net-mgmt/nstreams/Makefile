# New ports collection makefile for:	nstreams
# Date created:		22 September 1999
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	nstreams
PORTVERSION=	1.0.4
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.nessus.org/pub/nstreams/

MAINTAINER=	ecu@ipv42.net
COMMENT=	Analyses network traffic and produces ipfw rules to allow it

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

MAN1=		nstreams.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nstreams ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nstreams.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/docs/nstreams-networks \
	${PREFIX}/etc/nstreams-networks.sample
	${INSTALL_DATA} ${WRKSRC}/docs/nstreams-services ${PREFIX}/etc/nstreams-services

.include <bsd.port.mk>

# New ports collection makefile for:	beacon-server
# Date created:				2 May 2002
# Whom:					Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	beacon
PORTVERSION=	0.8.09
CATEGORIES=	net mbone perl5
MASTER_SITES=	http://dast.nlanr.net/Projects/Beacon/
PKGNAMESUFFIX=	-server
DISTNAME=	beaconserver_v${PORTVERSION}_perl

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Beacon active measurement tool to monitor multicast (server)

RUN_DEPENDS=	${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/IO/Socket/Multicast.pm:${PORTSDIR}/net/p5-IO-Socket-Multicast

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes

do-install:
	@if [ ! -d ${PREFIX}/beaconserver ]; then \
		${MKDIR} ${PREFIX}/beaconserver; fi
	${INSTALL_SCRIPT} -m 750 ${WRKDIR}/beaconserver_v${PORTVERSION}_htmlgen.pl ${PREFIX}/beaconserver/beaconserver_htmlgen.pl
	${INSTALL_SCRIPT} -m 750 ${WRKDIR}/beaconserver_v${PORTVERSION}_server.pl ${PREFIX}/beaconserver/beaconserver_server.pl
	${INSTALL_DATA} -m 644 ${WRKDIR}/LICENSE ${PREFIX}/beaconserver/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# Ports collection makefile for:	nessus-plugins
# Date created:				16 October 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-plugins
PORTVERSION=	1.0.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${NESSUS_REV}/src/

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${LOCALBASE}/include/nessus/config.h:${PORTSDIR}/security/nessus \
		${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap
RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

NESSUS_REV=	${DISTNAME:S/nessus-plugins-//g}

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes

MAN1=		nessus-build.1
MAN8=		nessus-update-plugins.8

.include <bsd.port.mk>

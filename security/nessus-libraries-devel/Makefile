# Ports collection makefile for:	nessus-libraries
# Date created:				07 Noevmber 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-libraries
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

NESSUS_REV=	${DISTNAME:S/nessus-libraries-//g}

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-libraries

USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--enable-cipher

MAN1=		nessus-config.1

.include <bsd.port.mk>

# Ports collection makefile for:	nessus-libraries
# Version required:			0.99.4
# Date created:				07 Noevmber 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

DISTNAME=	nessus-libraries-0.99.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${NESSUS_REV}/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${NESSUS_REV}/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${NESSUS_REV}/

MAINTAINER=	anders@fix.no

NESSUS_REV=	${DISTNAME:S/nessus-libraries-//g}

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-libraries

USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--enable-cipher

MAN1=		nessus-config.1

.include <bsd.port.mk>

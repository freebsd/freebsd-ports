# Ports collection makefile for:	nessus-libnasl
# Date created:				07 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-libnasl
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
DISTNAME=	libnasl-1.0.4

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	libnasl-patch-1

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	nessus.1:${PORTSDIR}/security/nessus-libraries

NESSUS_REV=	${DISTNAME:S/libnasl-//g}

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_LIBTOOL=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

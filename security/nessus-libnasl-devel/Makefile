# Ports collection makefile for:	nessus-libnasl
# Date created:				07 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-libnasl
PORTVERSION=	0.99.7
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
DISTNAME=	libnasl-0.99.7

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	nessus.99:${PORTSDIR}/security/nessus-libraries

NESSUS_REV=	${DISTNAME:S/libnasl-//g}

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_LIBTOOL=	YES

MAN1=		nasl-config.1

.include <bsd.port.mk>

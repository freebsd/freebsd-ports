# Ports collection makefile for:	nessus-libnasl
# Date created:				07 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	libnasl
PORTVERSION=	1.0.7a
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${PORTVERSION}/src/
PKGNAMEPREFIX=	nessus-

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	nessus.1:${PORTSDIR}/security/nessus-libraries

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_LIBTOOL=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

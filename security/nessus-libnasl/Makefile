# Ports collection makefile for:	nessus-libnasl
# Date created:				07 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	libnasl
PORTVERSION=	1.0.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${PORTVERSION}/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${PORTVERSION}/
PKGNAMEPREFIX=	nessus-

MAINTAINER=	olgeni@uli.it

LIB_DEPENDS=	nessus.1:${PORTSDIR}/security/nessus-libraries

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_LIBTOOL=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

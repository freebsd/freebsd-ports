# Ports collection makefile for:	nessus-libraries
# Date created:				07 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-libraries
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

MAINTAINER=	olgeni@uli.it

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-libraries

USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--enable-cipher
INSTALLS_SHLIB=	YES

MAN1=		nessus-config.1

.include <bsd.port.mk>

# Ports collection makefile for:	nessus-libraries-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-libraries-devel
PORTVERSION=	1.1.12
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://cvs.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/unstable/nessus-${PORTVERSION}/src/

MAINTAINER=	udo.schweigert@siemens.com

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-libraries
DISTNAME=	nessus-libraries-${PORTVERSION}

USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--enable-cipher
INSTALLS_SHLIB=	YES

MAN1=		nessus-config.1

.include <bsd.port.mk>

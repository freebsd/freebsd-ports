# Ports collection makefile for:	nessus-libnasl-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-libnasl-devel
PORTVERSION=	1.1.12
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://cvs.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/unstable/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/unstable/nessus-${PORTVERSION}/src/

MAINTAINER=	udo.schweigert@siemens.com	

LIB_DEPENDS=	nessus.2:${PORTSDIR}/security/nessus-libraries-devel

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl
DISTNAME=	libnasl-${PORTVERSION}

USE_LIBTOOL=	YES
INSTALLS_SHLIB=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

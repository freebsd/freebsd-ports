# Ports collection makefile for:	nessus-libnasl-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-libnasl-devel
PORTVERSION=	1.2.2
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
DISTNAME=	libnasl-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com

FORBIDDEN=	security/nessus-libnasl is newer

LIB_DEPENDS=	nessus.3:${PORTSDIR}/security/nessus-libraries-devel

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_LIBTOOL=	YES
INSTALLS_SHLIB=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

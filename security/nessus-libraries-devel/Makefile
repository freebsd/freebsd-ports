# Ports collection makefile for:	nessus-libraries-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-libraries-devel
PORTVERSION=	1.3.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/unstable/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-libraries-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-libraries

USE_BISON=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--enable-cipher --sharedstatedir=${PREFIX}/etc/nessus/com \
		--localstatedir=${PREFIX}/etc/nessus/var

INSTALLS_SHLIB=	YES

MAN1=		nessus-config.1

.include <bsd.port.mk>

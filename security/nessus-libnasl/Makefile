# Ports collection makefile for:	nessus-libnasl
# Date created:				07 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-libnasl
PORTVERSION=	2.0.10a
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.au.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	libnasl-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	Nessus Attack Scripting Language

LIB_DEPENDS=	nessus.2:${PORTSDIR}/security/nessus-libraries

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_BISON=	YES
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

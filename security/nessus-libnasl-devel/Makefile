# Ports collection makefile for:	nessus-libnasl-devel
# Date created:		27 Oct 2001
# Whom:			Udo Schweigert <udo.schweigert@siemens.com>
#
# $FreeBSD$
#

PORTNAME=	nessus-libnasl-devel
PORTVERSION=	2.1.2
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

CONFLICTS=	nessus-libnasl-[0-9]*

LIB_DEPENDS=	nessus.3:${PORTSDIR}/security/nessus-libraries-devel

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_BISON=	YES
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

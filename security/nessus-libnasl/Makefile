# Ports collection makefile for:	nessus-libnasl
# Date created:				07 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-libnasl
PORTVERSION=	2.2.9
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	libnasl-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	Nessus Attack Scripting Language

LIB_DEPENDS=	nessus.4:${PORTSDIR}/security/nessus-libraries

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_AUTOTOOLS=	libtool:22
USE_BISON=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

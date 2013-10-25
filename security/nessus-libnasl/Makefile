# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

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

LICENSE=	GPLv2

LIB_DEPENDS=	libnessus.so:${PORTSDIR}/security/nessus-libraries

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/libnasl

USE_AUTOTOOLS=	libtool
USES=		bison
GNU_CONFIGURE=	yes
USE_LDCONFIG=	YES

MAN1=		nasl.1 nasl-config.1

.include <bsd.port.mk>

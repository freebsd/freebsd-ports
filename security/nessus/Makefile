# New ports collection makefile for: 	nessus
# Date created:		1 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus
PORTVERSION=	1.0.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${NESSUS_REV}/src/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${NESSUS_REV}/src/
DISTNAME=	nessus-core-1.0.4

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	nasl.1:${PORTSDIR}/security/nessus-libnasl

NESSUS_REV=	${DISTNAME:S/nessus-core-//g}

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core

USE_GTK=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	GTKCONFIG="${GTK_CONFIG}"

MAN1=		nessus.1
MAN8=		nessusd.8 nessus-adduser.8

post-install:
	@${ECHO} "=========================================================="
	@${ECHO} "Be sure to erase your old ${PREFIX}/etc/nessus!"
	@${ECHO} "The syntax of nessusd.users and nessusd.rules has changed!"
	@${ECHO} "=========================================================="

.include <bsd.port.mk>

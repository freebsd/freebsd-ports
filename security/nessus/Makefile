# New ports collection makefile for: 	nessus
# Date created:		1 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus
PORTVERSION=	0.99.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${NESSUS_REV}/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${NESSUS_REV}/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${NESSUS_REV}/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${NESSUS_REV}/
DISTNAME=	nessus-core-0.99.7

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	nasl.99:${PORTSDIR}/security/nessus-libnasl \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

NESSUS_REV=	${DISTNAME:S/nessus-core-//g}
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTKCONFIG="${GTK_CONFIG}"
MAN1=		nessus.1
MAN8=		nessusd.8

post-install:
		@${ECHO} "=========================================================="
		@${ECHO} "Be sure to erase your old ${PREFIX}/etc/nessus!"
		@${ECHO} "The syntax of nessusd.users and nessusd.rules has changed!"
		@${ECHO} "=========================================================="

.include <bsd.port.mk>

# New ports collection makefile for: 	nessus
# Version required:	alpha2-fix4
# Date created:		1 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

DISTNAME=	nessus-alpha2-fix4
PKGNAME=	nessus-a2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-RELEASE/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-RELEASE/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-RELEASE/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-RELEASE/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-RELEASE/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-RELEASE/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-RELEASE/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-RELEASE/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-RELEASE/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTKCONFIG="${GTK_CONFIG}"
MAN1=		nessus.1

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

# New ports collection makefile for:    cd-write
# Version required:     1.4
# Date created:         1 May 1997
# Whom:                 jmz
#
# $Id: Makefile,v 1.10 1998/10/09 10:05:56 asami Exp $
#

DISTNAME=       cd-write-1.4
CATEGORIES=     sysutils
MASTER_SITES=   ftp://ftp.obs-besancon.fr/pub/outgoing/

MAINTAINER=     jmz@FreeBSD.org

LIB_DEPENDS=	tixsam4180.1:${PORTSDIR}/x11-toolkits/tix

WRKSRC=		${WRKDIR}/cd-write

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=		scsi.h
.endif

pre-build:
	@cd ${WRKSRC}; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile;\
		echo all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

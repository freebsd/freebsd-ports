# New ports collection makefile for:	dgd-lpmud
# Version required:	2.4.5
# Date created:		10 November 1994
# Whom:			adam
#
# $Id: Makefile,v 1.9 1996/03/19 14:45:55 adam Exp $
#

DISTNAME=	dgd-lpmud
PKGNAME=	dgd-lpmud-2.4.5
CATEGORIES+=	net devel games
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/
DISTFILES=	2.4.5-for-1.0.37.tgz
#DISTFILES=	sim-2.4.5.tar.gz

MAINTAINER=	adam@veda.is

RUN_DEPENDS=	${PREFIX}/dgd/bin/driver:${PORTSDIR}/net/dgd

NO_WRKSUBDIR=
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-p ${PREFIX}/dgd
#		-r ${PKGDIR}/REQ

do-build:
	@cd ${WRKDIR}/bin; make

do-install:
	@tar -C ${WRKDIR} -cf - `grep '^[a-z]' pkg/PLIST` \
		| tar -C ${PREFIX}/dgd -xpf -

.include <bsd.port.mk>

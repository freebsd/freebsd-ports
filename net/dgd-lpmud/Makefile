# New ports collection makefile for:	dgd-lpmud
# Version required:	2.4.5
# Date created:		10 November 1994
# Whom:			adam
#
# $Id: Makefile,v 1.12 1996/06/17 17:34:16 adam Exp $
#

DISTNAME=	dgd-lpmud
PKGNAME=	dgd-lpmud-2.4.5
CATEGORIES+=	net devel games
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/
DISTFILES=	2.4.5-for-1.0.37.tgz
#DISTFILES=	sim-2.4.5.tar.gz
DIST_SUBDIR=	dgd

MAINTAINER=	adam@veda.is

NO_CDROM=	depends on DGD, which is NO_CDROM
RESTRICTED=	no monetary gain

RUN_DEPENDS=	${PREFIX}/dgd/bin/driver:${PORTSDIR}/net/dgd

NO_WRKSUBDIR=
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-p ${PREFIX}/dgd
#		-r ${PKGDIR}/REQ

do-build:
	@cd ${WRKDIR}/bin; make

do-install:
	@tar -C ${WRKDIR} -cf - `grep '^[a-z]' ${PKGDIR}/PLIST` \
		| tar -C ${PREFIX}/dgd -xpf -

.include <bsd.port.mk>

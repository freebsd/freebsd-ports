# New ports collection makefile for:	dgd-lpmud
# Version required:	2.4.5
# Date created:		10 November 1994
# Whom:			adam
#
# $Id: Makefile,v 1.8 1996/02/29 08:50:30 asami Exp $
#

DISTNAME=	dgd-lpmud
PKGNAME=	dgd-lpmud-2.4.5
CATEGORIES+=	net devel games
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/ \
		ftp://ftp.lysator.liu.se/pub/lpmud/mudlibs/other/
DISTFILES=	sim-2.4.5.tar.gz 2.4.5.tar.gz

PATCH_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/
PATCHFILES=	sim-diffs

MAINTAINER=	adam@veda.is

RUN_DEPENDS=	${PREFIX}/dgd/bin/driver:${PORTSDIR}/net/dgd

NO_WRKSUBDIR=
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-p ${PREFIX}/dgd
#		-r ${PKGDIR}/REQ

pre-patch:
	@cd ${WRKDIR}; patch -s <2.4.5/diffs; mv 2.4.5/dgd .

do-build:
	@cd ${WRKDIR}/bin; make

do-install:
	@tar -C ${WRKDIR} -cf - `grep '^[a-z]' pkg/PLIST` \
		| tar -C ${PREFIX}/dgd -xpf -

.include <bsd.port.mk>

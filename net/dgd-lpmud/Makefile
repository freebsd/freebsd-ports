# New ports collection makefile for:	dgd-lpmud
# Version required:	2.4.5
# Date created:		10 November 1994
# Whom:			adam
#
# $Id: Makefile,v 1.14 1996/10/31 19:33:20 adam Exp $
#

DISTNAME=	dgd-lpmud
PKGNAME=	dgd-lpmud-2.4.5
CATEGORIES+=	net devel games
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/
DISTFILES=	2.4.5-for-1.1.tgz
DIST_SUBDIR=	dgd

MAINTAINER=	adam@veda.is

NO_PACKAGE=	depends on DGD, which is NO_CDROM
RESTRICTED=	no monetary gain, tarball OK for CDROM

RUN_DEPENDS=	${PREFIX}/dgd/bin/driver:${PORTSDIR}/net/dgd

WRKSRC=		${WRKDIR}/mud
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-p ${PREFIX}/dgd
#		-r ${PKGDIR}/REQ

do-build:
	@cd ${WRKDIR}/bin; make

do-install:
	@tar -C ${WRKDIR} -cf - `grep '^[a-z]' ${PKGDIR}/PLIST` \
		| tar -C ${PREFIX}/dgd -xpf -

.include <bsd.port.mk>

# New ports collection makefile for:	dgd-lpmud
# Version required:	2.4.5
# Date created:		10 November 1994
# Whom:			adam
#
# $Id: Makefile,v 1.3 1995/04/15 05:41:24 asami Exp $
#

DISTNAME=	dgd-lpmud
PKGNAME=	dgd-lpmud-2.4.5
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/ \
		ftp://ftp.lysator.liu.se/pub/lpmud/mudlibs/other/
DISTFILES=	sim-2.4.5.tar.gz 2.4.5.tar.gz

DEPENDS=	${PORTSDIR}/net/dgd

NO_WRKSUBDIR=
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-r ${PKGDIR}/REQ

.include <bsd.port.mk>

# New ports collection makefile for:	dgd-lpmud
# Version required:	2.4.5
# Date created:		10 November 1994
# Whom:			adam
#

DISTNAME=	dgd-lpmud
DISTFILES=	sim-2.4.5.tar.gz 2.4.5.tar.gz
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/ \
CATEGORIES+=	networking
		ftp://ftp.lysator.liu.se/pub/lpmud/mudlibs/other/
NCFTPFLAGS=	-P

NO_WRKSUBDIR=

DEPENDS=	${PORTSDIR}/net/dgd

PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-r ${PKGDIR}/REQ

.include <bsd.port.mk>

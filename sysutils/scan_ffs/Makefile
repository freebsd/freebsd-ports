# New ports collection makefile for: scan_ffs
# Date created:         20040112
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=	scan_ffs
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ranner.jawa.at/stuff/

MAINTAINER=	mranner@inode.at
COMMENT=	Scan_ffs recovers lost disklabel

MAN8=		scan_ffs.8
PLIST_FILES=	sbin/scan_ffs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scan_ffs ${PREFIX}/sbin/.
	${INSTALL_MAN} ${WRKSRC}/scan_ffs.8 ${MAN8PREFIX}/man/man8/.

.include <bsd.port.mk>

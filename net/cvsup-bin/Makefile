# New ports collection makefile for:	cvsup-bin
# Version required:	15.4.2
# Date created:		12 November 1997
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $Id: Makefile,v 1.4 1998/04/28 22:25:52 jdp Exp $
#

DISTNAME=	cvsup-bin-15.4.2
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/CVSup/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/CVSup/ \
		ftp://ftp.polstra.com/pub/FreeBSD/CVSup/
DISTFILES=	cvsup-bin-15.4.2.tar.gz

MAINTAINER=	axl@iafrica.com

NO_BUILD=	yes

MAN1=	cvsup.1

# Uncomment the next line if you want cvsupd as well
# USE_CVSUPD=	yes

.ifdef USE_CVSUPD
DISTFILES+=	cvsupd-bin-15.4.2.tar.gz
MAN8=		cvsupd.8
PLIST=		${PKGDIR}/PLIST.cvsupd
.endif

do-install:
	cd ${WRKDIR}/cvsup-bin-15.4.2; \
	    ${INSTALL_PROGRAM} cvsup ${PREFIX}/bin; \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.ifdef USE_CVSUPD
	cd ${WRKDIR}/cvsupd-bin-15.4.2; \
	    ${INSTALL_PROGRAM} cvsupd ${PREFIX}/sbin; \
	    ${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	cvsupd-bin
# Version required:	15.4.2
# Date created:		17 August 1998
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $Id: Makefile,v 1.1.1.1 1998/08/17 21:37:02 jdp Exp $
#

DISTNAME=	cvsupd-bin-15.4.2
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/CVSup/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/CVSup/ \
		ftp://ftp.polstra.com/pub/FreeBSD/CVSup/
DISTFILES=	cvsupd-bin-15.4.2.tar.gz

MAINTAINER=	axl@iafrica.com

NO_BUILD=	yes

MAN8=	cvsupd.8
STRIP=

do-configure:
	cd ${WRKSRC}; gunzip cvsupd.8.gz

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} cvsupd ${PREFIX}/sbin; \
	    ${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>

# New ports collection makefile for:	cvsupd-bin
# Version required:	16.0
# Date created:		17 August 1998
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $Id: Makefile,v 1.3 1999/02/10 02:48:00 jdp Exp $
#

DISTNAME=	cvsupd-bin-16.0
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/development/CVSup/
DISTFILES=	cvsupd-bin-16.0.tar.gz

MAINTAINER=	jdp@freebsd.org

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

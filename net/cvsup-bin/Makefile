# New ports collection makefile for:	cvsup-bin
# Version required:	15.4.2
# Date created:		12 November 1997
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $Id: Makefile,v 1.6 1998/08/17 21:44:57 jdp Exp $
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
STRIP=

do-configure:
	cd ${WRKSRC}; gunzip cvsup.1.gz

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} cvsup ${PREFIX}/bin; \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>

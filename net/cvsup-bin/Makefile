# New ports collection makefile for:	cvsup-bin
# Version required:	16.0
# Date created:		12 November 1997
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $Id: Makefile,v 1.7 1998/09/22 23:20:54 jdp Exp $
#

DISTNAME=	cvsup-bin-16.0
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/development/CVSup/
DISTFILES=	cvsup-bin-16.0.tar.gz

MAINTAINER=	axl@iafrica.com

NO_BUILD=	yes

MAN1=	cvpasswd.1 cvsup.1
STRIP=

do-configure:
	cd ${WRKSRC}; gunzip ${MAN1:S/$/.gz/}

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} cvpasswd cvsup ${PREFIX}/bin; \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>

# New ports collection makefile for:	cvsupd-bin
# Version required:	16.0
# Date created:		17 August 1998
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $Id: Makefile,v 1.5 1999/03/06 22:40:25 wosch Exp $
#

DISTNAME=	cvsupd-bin-16.0
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/
DISTFILES=	cvsupd-bin-16.0.tar.gz

MAINTAINER=	jdp@freebsd.org

ONLY_FOR_ARCHS=	i386

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

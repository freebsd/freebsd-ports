# ex:ts=8
# Ports collection makefile for:  hbiff
# Version required:     	  1.2
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	hbiff-1.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nuxi.com/pub/misc/  \
		http://www.freebsd.org/~obrien/Distfiles/

MAINTAINER=     obrien@FreeBSD.org

USE_XLIB=	yes
MAN1=		hbiff.1

do-build:
	cd ${WRKSRC} ; cc -I${X11BASE}/include hbiff.c -L${X11BASE}/lib -lX11

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/hbiff
	@cd ${WRKSRC} ; ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>

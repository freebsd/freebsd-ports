# ex:ts=8
# Ports collection makefile for:  hbiff
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	hbiff
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/misc/  \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	A replacement for xbiff that handles popup window with mail headers

USE_XLIB=	yes
MAN1=		hbiff.1

do-build:
	cd ${WRKSRC} ; cc -I${X11BASE}/include hbiff.c -L${X11BASE}/lib -lX11

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/hbiff
	@cd ${WRKSRC} ; ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>

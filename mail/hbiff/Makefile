# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	hbiff
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/misc/  \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	A replacement for xbiff that handles popup window with mail headers

USE_XORG=	x11
MAN1=		hbiff.1

NO_STAGE=	yes
do-build:
	cd ${WRKSRC} ; cc -I${LOCALBASE}/include hbiff.c -L${LOCALBASE}/lib -lX11

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/hbiff
	@cd ${WRKSRC} ; ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>

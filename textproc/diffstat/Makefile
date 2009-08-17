# New ports collection makefile for:	diffstat
# Date created:		Oct 23, 1999
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	diffstat
PORTVERSION=	1.48
CATEGORIES=	textproc devel
MASTER_SITES=	ftp://dickey.his.com/diffstat/
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Makes a histogram summarizing "diff" output

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		diffstat.1
PLIST_FILES=	bin/diffstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diffstat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

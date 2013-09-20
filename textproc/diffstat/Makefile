# Created by: trevor
# $FreeBSD$

PORTNAME=	diffstat
PORTVERSION=	1.57
CATEGORIES=	textproc devel
MASTER_SITES=	ftp://invisible-island.net/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Makes a histogram summarizing "diff" output

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		diffstat.1
PLIST_FILES=	bin/diffstat

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diffstat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

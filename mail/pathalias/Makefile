# $FreeBSD$

PORTNAME=	pathalias
PORTVERSION=	9.16
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.dinoex.de/pub/approved/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mail routing tools

ALL_TARGET=	pathalias

PLIST_FILES=	bin/pathalias man/man8/pathalias.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathalias ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pathalias.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>

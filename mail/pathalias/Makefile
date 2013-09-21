# $FreeBSD$

PORTNAME=	pathalias
PORTVERSION=	9.16
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.dinoex.de/pub/approved/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mail routing tools

NO_STAGE=	yes

ALL_TARGET=	pathalias

MAN8=		pathalias.8
BIN8=		pathalias
PLIST_FILES=	bin/pathalias

do-install:
.for i in ${BIN8}
	@${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man8
.endfor

.include <bsd.port.mk>

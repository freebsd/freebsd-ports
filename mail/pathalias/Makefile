# New ports collection makefile for:	pathalias
# Date created:		03 Dec 1997
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pathalias
PORTVERSION=	9.11
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.lan-ks.de/pub/approved/ \
		ftp://ftp.dinoex.de/pub/approved/
DISTNAME=	${PORTNAME}11
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dirk.meyer@dinoex.sub.org

ALL_TARGET=	pathalias

MAN8=		pathalias.8
BIN8=		pathalias

do-install:
.for i in ${BIN8}
	@${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man8
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:	fileshuffle
# Date created:		2008-05-29
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fileshuffle
PORTVERSION=	0.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.eskimo.com/u/s/scs/src/
DISTNAME=	shuffle

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A filter for shuffling lines in a text file into random order

MANPAGE=	shuffle.1

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
		@${CP} ${WRKSRC}/shuffle ${PREFIX}/bin/${PORTNAME}
		@${CP} ${WRKSRC}/${MANPAGE} ${PREFIX}/man/man1/${PORTNAME}.1
.include <bsd.port.mk>

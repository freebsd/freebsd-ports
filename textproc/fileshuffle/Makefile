# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fileshuffle
PORTVERSION=	0.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.eskimo.com/u/s/scs/src/
DISTNAME=	shuffle

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter for shuffling lines in a text file into random order

.if ${CC:Mclang}
BROKEN=		Does not compile with clang, use gshuf from sysutils/coreutils instead
.endif
DEPRECATED=	Does not work, use gshuf from sysutils/coreutils instead
EXPIRATION_DATE=2013-09-23

MANPAGE=	shuffle.1

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
		@${CP} ${WRKSRC}/shuffle ${PREFIX}/bin/${PORTNAME}
		@${CP} ${WRKSRC}/${MANPAGE} ${PREFIX}/man/man1/${PORTNAME}.1
.include <bsd.port.mk>

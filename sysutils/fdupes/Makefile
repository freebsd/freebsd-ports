# New ports collection makefile for:	fdupes
# Date created:				27 December 2004
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	fdupes
DISTVERSION=	1.50-PR2
CATEGORIES=	sysutils
MASTER_SITES=	http://netdial.caribe.net/~adrian2/programs/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fdupes is a program for identifying or deleting duplicate files

MAN1=		fdupes.1
PLIST_FILES=	bin/fdupes

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 500041)
CFLAGS+=	-DOMIT_GETOPT_LONG=yes
.endif

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/md5/md5.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>

# New ports collection makefile for:	fdupes
# Date created:				27 December 2004
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	fdupes
PORTVERSION=	1.40
CATEGORIES=	sysutils
MASTER_SITES=	http://netdial.caribe.net/~adrian2/programs/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Fdupes is a program for identifying or deleting duplicate files

USE_GETOPT_LONG=	yes

MAN1=		fdupes.1
PLIST_FILES=	bin/fdupes

.include <bsd.port.pre.mk>

CFLAGS+=	-DHAVE_DECL_GETOPT

do-build:
.if ${OSVERSION} < 500041
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/md5/md5.c -o ${WRKSRC}/${PORTNAME} -DVERSION=\"${PORTVERSION}\" -I${LOCALBASE}/include ${LOCALBASE}/lib/libgnugetopt.so
.else
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/md5/md5.c -o ${WRKSRC}/${PORTNAME} -DVERSION=\"${PORTVERSION}\"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>

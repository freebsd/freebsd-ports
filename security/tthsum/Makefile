# New ports collection makefile for:	tthsum
# Date created:				25 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	tthsum
PORTVERSION=	1.1.0
CATEGORIES=	security
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line utility for generating and checking TTH message digests

USE_GMAKE=	yes

MAKE_ENV=	LDFLAGS="${LDFLAGS}"

PORTDOCS=	Changelog.txt
PLIST_FILES=	bin/tthsum
MAN1=		tthsum.1

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,g' \
		${WRKSRC}/base32.c \
		${WRKSRC}/read.c \
		${WRKSRC}/utf8.c
	@${REINPLACE_CMD} '/stdio.h/H; /stdio\.h/{ p; s/#include <stdio.h>/#define O_LARGEFILE 0/;}' \
		${WRKSRC}/read.c \
		${WRKSRC}/thex.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj-${ARCH}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

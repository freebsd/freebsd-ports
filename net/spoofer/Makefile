# New ports collection makefile for:	spoofer
# Date created:		6 February 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spoofer
PORTVERSION=	0.4
CATEGORIES=	net
MASTER_SITES=	http://spoofer.csail.mit.edu/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	ANA Spoofer Project testing software

PLIST_FILES=	bin/spoofer
PORTDOCS=	README CHANGES

SRC=		spoofer.c util.c trace.c
CFLAGS+=	-D_FBSD

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} -c ${WRKSRC}/${f} -o ${WRKSRC}/${f:C/\.c$/.o/}
.endfor
	${CC} ${SRC:C/(.*)\.c$/${WRKSRC}\/\1.o/} -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

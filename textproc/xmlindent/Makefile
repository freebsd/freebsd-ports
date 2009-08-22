# ex:ts=8
# Ports collection makefile for:	xmlindent
# Date created:			Apr 1, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlindent
PORTVERSION=	0.2.17
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	david@trucs.org
COMMENT=	XML stream reformatter

MANCOMPRESSED=	no

SOURCES=	error.c indent.c buffer.c main.c

MAN1=		xmlindent.1
PLIST_FILES=	bin/xmlindent

do-build:
	@cd ${WRKSRC}; flex xmlindent.yy
	${CC} ${CFLAGS} ${SOURCES:C/(.*)/${WRKSRC}\/\1/} -o ${WRKSRC}/${PORTNAME} -lfl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>

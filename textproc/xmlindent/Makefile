# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlindent
PORTVERSION=	0.2.17
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XML stream reformatter

LICENSE=	GPLv2

MANCOMPRESSED=	no

SOURCES=	error.c indent.c buffer.c main.c

MAN1=		xmlindent.1
PLIST_FILES=	bin/xmlindent

do-build:
	@cd ${WRKSRC}; flex xmlindent.yy
	${CC} ${CFLAGS} ${SOURCES:C/(.*)/${WRKSRC}\/\1/} \
		-o ${WRKSRC}/${PORTNAME} -lfl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>

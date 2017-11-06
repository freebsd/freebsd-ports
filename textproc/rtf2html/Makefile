# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	rtf2html
DISTVERSION=	1.1b
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple rtf2html converter

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	p5-RTF-Parser-[0-9]*

PLIST_FILES=	bin/rtf2html

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

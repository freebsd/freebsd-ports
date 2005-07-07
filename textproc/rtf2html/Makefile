# New ports collection makefile for:	rtf2html
# Date created:				 6 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	rtf2html
DISTVERSION=	1.1b
CATEGORIES=	textproc
MASTER_SITES=	http://www.45.free.net/~vitus/ice/misc/
DISTNAME=	${PORTNAME}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A simple rtf2html converter

CFLAGS+=	-Wall -Werror
PLIST_FILES=	bin/rtf2html

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>

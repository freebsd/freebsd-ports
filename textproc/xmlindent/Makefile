# ex:ts=8
# Ports collection makefile for:	xmlindent
# Date created:			Apr 1, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlindent
PORTVERSION=	0.2.12
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XML stream reformatter

MAN1=	xmlindent.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/xmlindent

pre-build:
	cd ${WRKSRC} && ${MAKE} lexer

.for t in build install
do-$t:
	cd ${WRKSRC} && ${MAKE} -f /usr/share/mk/bsd.prog.mk PROG=xmlindent \
		SRCS="error.c indent.c buffer.c main.c" \
		BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/man/man" \
		${t:build=all} LDADD=-lfl
.endfor

.include <bsd.port.mk>

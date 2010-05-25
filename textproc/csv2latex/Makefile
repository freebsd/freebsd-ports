# ex:ts=8
# Ports collection makefile for:	csv2latex
# Date created:			May 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	csv2latex
PORTVERSION=	0.18
PORTEPOCH=	1
CATEGORIES=	textproc converters
MASTER_SITES=	http://herewe.servebeer.com/csv2latex/releases/ \
		http://brouits.free.fr/csv2latex/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Converts a well formed csv file to a LaTeX document

PLIST_FILES=	bin/csv2latex

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if ( defined(WITH_MAN) &&  !defined(NO_INSTALL_MANPAGES) )
BUILD_DEPENDS +=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man
MAN1=	${PORTNAME}.1

post-build:
	docbook-to-man ${WRKSRC}/${PORTNAME}.sgml > ${WRKSRC}/${MAN1}

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.endif

.include <bsd.port.mk>

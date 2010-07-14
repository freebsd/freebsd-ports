# New ports collection makefile for:	qt-faststart
# Date created:		2010 January 26
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	qt-faststart
PORTVERSION=	0.2
CATEGORIES=	multimedia
MASTER_SITES=	#none
DISTFILES=	#none

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Convert QuickTime movie files to streamable format

PLIST_FILES=	bin/qt-faststart

.include <bsd.port.pre.mk>

do-extract:
		${MKDIR} ${WRKSRC}
		${CP} ${FILESDIR}/${PORTNAME}.c ${WRKSRC}

do-build:
		cd ${WRKSRC} && \
		${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>

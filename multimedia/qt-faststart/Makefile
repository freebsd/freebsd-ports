# New ports collection makefile for:	qt-faststart
# Date created:		2010 January 26
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	qt-faststart
PORTVERSION=	0.1
CATEGORIES=	multimedia
DISTFILES=

MAINTAINER=	fbsd@opal.com
COMMENT=	Convert QuickTime movie files to streamable format

PLIST_FILES=	bin/qt-faststart

.include <bsd.port.pre.mk>

do-fetch:

do-extract:
		${MKDIR} ${WRKSRC}
		${CP} ${FILESDIR}/${PORTNAME}.c ${WRKSRC}

do-build:
		cd ${WRKSRC}; ${CC} ${PORTNAME}.c -o ${PORTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>

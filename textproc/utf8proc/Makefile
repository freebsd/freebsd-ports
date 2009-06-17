# New ports collection makefile for:	utf8proc
# Date created:		2007-10-15
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	utf8proc
PORTVERSION=	1.1.3
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.flexiguided.de/pub/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	UTF-8 processing library

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	c-library

USE_LDCONFIG=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/libutf8proc.so ${PREFIX}/lib/libutf8proc.so.1
		${INSTALL_DATA} ${WRKSRC}/libutf8proc.a ${PREFIX}/lib
		${INSTALL_DATA} ${WRKSRC}/utf8proc.h ${PREFIX}/include
		${LN} -sf ${PREFIX}/lib/libutf8proc.so.0 ${PREFIX}/lib/libutf8proc.so

.include <bsd.port.mk>

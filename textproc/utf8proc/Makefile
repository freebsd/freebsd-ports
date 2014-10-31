# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utf8proc
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.public-software-group.org/pub/projects/${PORTNAME}/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	UTF-8 processing library

ALL_TARGET=	c-library

USE_LDCONFIG=	yes

do-install:
		${INSTALL_LIB} ${WRKSRC}/libutf8proc.so ${STAGEDIR}${PREFIX}/lib/libutf8proc.so.1
		${INSTALL_DATA} ${WRKSRC}/libutf8proc.a ${STAGEDIR}${PREFIX}/lib
		${INSTALL_DATA} ${WRKSRC}/utf8proc.h ${STAGEDIR}${PREFIX}/include
		${LN} -sf libutf8proc.so.1 ${STAGEDIR}${PREFIX}/lib/libutf8proc.so

.include <bsd.port.mk>

# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utf8proc
PORTVERSION=	1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-8 processing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	JuliaLang

USES=		gmake
USE_LDCONFIG=	yes

do-install:
	${INSTALL_LIB} ${WRKSRC}/libutf8proc.so ${STAGEDIR}${PREFIX}/lib/libutf8proc.so.1.2.0
	${INSTALL_DATA} ${WRKSRC}/libutf8proc.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/utf8proc.h ${STAGEDIR}${PREFIX}/include
	${LN} -sf libutf8proc.so.1.2.0 ${STAGEDIR}${PREFIX}/lib/libutf8proc.so.1.2
	${LN} -sf libutf8proc.so.1.2.0 ${STAGEDIR}${PREFIX}/lib/libutf8proc.so.1
	${LN} -sf libutf8proc.so.1.2.0 ${STAGEDIR}${PREFIX}/lib/libutf8proc.so

.include <bsd.port.mk>

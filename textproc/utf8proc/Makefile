# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utf8proc
PORTVERSION=	1.3
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

PORTDOCS=	NEWS.md README.md
PLIST_FILES=	include/utf8proc.h \
		lib/libutf8proc.a \
		lib/libutf8proc.so \
		lib/libutf8proc.so.1 \
		lib/libutf8proc.so.1.3 \
		lib/libutf8proc.so.1.3.0

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} utf8proc.h \
		${STAGEDIR}${PREFIX}/include)
	(cd ${WRKSRC} && ${INSTALL_DATA} libutf8proc.a \
		${STAGEDIR}${PREFIX}/lib)
	(cd ${WRKSRC} && ${INSTALL_LIB} libutf8proc.so.1.3.0 \
		${STAGEDIR}${PREFIX}/lib)
	${LN} -sf libutf8proc.so.1.3.0 \
		${STAGEDIR}${PREFIX}/lib/libutf8proc.so.1.3
	${LN} -sf libutf8proc.so.1.3.0 \
		${STAGEDIR}${PREFIX}/lib/libutf8proc.so.1
	${LN} -sf libutf8proc.so.1.3.0 \
		${STAGEDIR}${PREFIX}/lib/libutf8proc.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

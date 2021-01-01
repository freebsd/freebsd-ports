# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utf8proc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	textproc devel

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	UTF-8 processing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake perl5

USE_GITHUB=	yes
GH_ACCOUNT=	JuliaStrings
USE_LDCONFIG=	yes

MAKE_ARGS=	prefix=${PREFIX}

CONFLICTS=	libutf8proc-[0-9]*

PLIST_FILES=	include/utf8proc.h \
		lib/libutf8proc.a \
		lib/libutf8proc.so \
		lib/libutf8proc.so.2 \
		lib/libutf8proc.so.2.4.1 \
		libdata/pkgconfig/libutf8proc.pc
PORTDOCS=	NEWS.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libutf8proc.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

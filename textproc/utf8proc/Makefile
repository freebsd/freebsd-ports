# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utf8proc
PORTVERSION=	1.3.1
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
MAKE_ARGS=	prefix=${PREFIX}

PORTDOCS=	NEWS.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libutf8proc.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

PORTNAME=	tnef2txt
PORTVERSION=	1.4
CATEGORIES=	textproc converters
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable application/ms-tnef parser

ALL_TARGET=	tnef2txt
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/tnef2txt
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

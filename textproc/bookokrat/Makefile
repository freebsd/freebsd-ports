PORTNAME=	bookokrat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal EPUB book reader
WWW=		https://bugzmanov.github.io/bookokrat/index.html

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSL CC0-1.0 CDDL ISCL MIT MPL20 \
		UNLICENSE ZLIB
LICENSE_COMB=	multi

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bugzmanov

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/bookokrat
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bookokrat

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

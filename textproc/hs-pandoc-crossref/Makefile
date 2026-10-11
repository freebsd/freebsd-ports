PORTNAME=	pandoc-crossref
DISTVERSION=	0.3.26
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Pandoc filter for numbering figures and tables
WWW=		https://hackage.haskell.org/package/pandoc-crossref

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pandoc:textproc/hs-pandoc

USES=		cabal

CABAL_EXECUTABLES=	pandoc-crossref
SKIP_CABAL_PLIST=	yes

PLIST_FILES=	bin/pandoc-crossref \
		share/man/man1/pandoc-crossref.1.gz

post-build:
	cd ${WRKSRC}/docs && ${LOCALBASE}/bin/pandoc -s -t man index.md -o pandoc-crossref.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/pandoc-crossref.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

PORTNAME=	treemd
DISTVERSIONPREFIX=	v
# XXX: check if you still need to override MASTER_SITE for Rust crates
# see PR 298395
DISTVERSION=	0.8.0
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TUI/CLI markdown navigator with tree-based structural navigation
WWW=		https://github.com/epistates/treemd

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSL CC0-1.0 ISCL MIT MPL20 \
		UNLICENSE ZLIB
LICENSE_COMB=	multi

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	epistates

PLIST_FILES=	bin/treemd
PORTDOCS=	QUERY_LANGUAGE.md

OPTIONS_DEFINE=	DOCS

# XXX
IGNORE_MASTER_SITE_CRATESIO=	yes
MASTER_SITE_CRATESIO=		https://static.crates.io/crates/%SUBDIR%/download?dummy=/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/QUERY_LANGUAGE.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

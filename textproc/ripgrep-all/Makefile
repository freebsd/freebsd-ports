PORTNAME=	ripgrep-all
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.10
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	eduardo@freebsd.org
COMMENT=	Improved search capacities of ripgrep
WWW=		https://github.com/phiresky/ripgrep-all/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rg:textproc/ripgrep
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	phiresky

PLIST_FILES=	bin/rga \
		bin/rga-preproc \
		bin/rga-fzf \
		bin/rga-fzf-open

.include <bsd.port.mk>

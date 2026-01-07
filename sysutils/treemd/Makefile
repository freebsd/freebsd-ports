PORTNAME=	treemd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
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

.include <bsd.port.mk>

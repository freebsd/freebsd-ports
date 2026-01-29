PORTNAME=	mdfried
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Markdown viewer for the terminal that renders images and big headers
WWW=		https://crates.io/crates/mdfried

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE CC0-1.0 GPLv3 ISCL MIT MPL20 \
		NCSA UNICODE UNICODE-DFS-2016 WTFPL ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	Unicode Terms of Use
LICENSE_NAME_UNICODE-DFS-2016=	Unicode License Agreement - Data Files and Software (2016)
LICENSE_TEXT_UNICODE=	See https://spdx.org/licenses/Unicode-TOU.html
LICENSE_TEXT_UNICODE-DFS-2016=	See https://spdx.org/licenses/Unicode-DFS-2016.html
LICENSE_PERMS_UNICODE=		dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept
LICENSE_PERMS_UNICODE-DFS-2016=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

LIB_DEPENDS=	libchafa.so:graphics/chafa

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	benjajaja

PLIST_FILES=	bin/mdfried
PORTDOCS=	README.md assets/screenshot_1.png

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/assets
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor

.include <bsd.port.mk>

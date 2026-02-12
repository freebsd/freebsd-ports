PORTNAME=	rustic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	sysutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Fast, encrypted, and deduplicated backups powered by Rust
WWW=		https://rustic.cli.rs/

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE BSL CC0-1.0 CDLA20 \
		MIT MPL20 UNICODE UNLICENSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_CDLA20=	Community Data License Agreement – Permissive, Version 2.0
LICENSE_NAME_UNICODE=	Unicode Terms of Use
LICENSE_TEXT_CDLA20=	See https://cdla.dev/permissive-2-0/
LICENSE_TEXT_UNICODE=	See https://spdx.org/licenses/Unicode-TOU.html
LICENSE_PERMS_CDLA20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rustic-rs

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|\[/config/\](/config)|[examples](${EXAMPLESDIR})|1' \
		-e 's|\[\(services\)/\](/config/services/)|[examples/\1/](${EXAMPLESDIR}/\1)|1' \
		${WRKSRC}/config/README.md

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/config && \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! ( -name *.md -or -name *.bak )")

.include <bsd.port.mk>

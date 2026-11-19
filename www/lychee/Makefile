PORTNAME=	lychee
DISTVERSIONPREFIX=	lychee-v
DISTVERSION=	0.18.1
CATEGORIES=	www net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Link checker
WWW=		https://github.com/lycheeverse/lychee

LICENSE=	Apache-2.0 MIT Unicode-3.0 Unicode-DFS-2016 BSD-3-Clause \
		BSD-2-Clause Zlib MPL-2.0 AGPL-3.0-or-later
LICENSE_COMB=	multi
LICENSE_FILE_Apache-2.0=${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_Unicode-3.0=	${WRKSRC}/cargo-crates/icu_properties-1.5.1/LICENSE
LICENSE_FILE_Unicode-DFS-2016=	${WRKSRC}/cargo-crates/unicode-ident-1.0.13/LICENSE-UNICODE
LICENSE_FILE_BSD-3-Clause=	${WRKSRC}/cargo-crates/sha1-0.6.1/LICENSE
LICENSE_FILE_BSD-2-Clause=	${WRKSRC}/cargo-crates/ip_network-0.4.1/LICENSE
LICENSE_FILE_Zlib=	${WRKSRC}/cargo-crates/const_format-0.2.34/LICENSE-ZLIB.md
LICENSE_FILE_MPL-2.0=	${WRKSRC}/cargo-crates/ascii_utils-0.9.3/LICENSE_MPL-2.0.txt
LICENSE_FILE_AGPL-3.0-or-later=	${FILESDIR}/LICENSE.AGPL-3.0-or-later

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	lycheeverse

PLIST_FILES=	bin/lychee

CARGO_INSTALL_PATH=	lychee-bin

.include <bsd.port.mk>

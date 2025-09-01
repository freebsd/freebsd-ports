PORTNAME=	wasm-bindgen-cli
DISTVERSION=	0.2.95
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	aokblast@FreeBSD.org
COMMENT=	CLI tool to generate Rust bindings for Wasm
WWW=		https://rustwasm.github.io/wasm-bindgen/ \
		https://github.com/rustwasm/wasm-bindgen

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	zstd>0:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	rustwasm
GH_PROJECT=	wasm-bindgen

CARGO_INSTALL_PATH=	crates/cli

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

.include <bsd.port.mk>

PORTNAME=	kalker
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
DISTVERSIONSUFFIX=	-2
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scientific calculator that supports math-like syntax

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	PaddiM8
CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		az-1.0.0 \
		bitflags-1.2.1 \
		bumpalo-3.4.0 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		console_error_panic_hook-0.1.6 \
		dirs-3.0.2 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.6 \
		dirs-sys-next-0.1.1 \
		fs2-0.4.3 \
		getrandom-0.1.15 \
		getrandom-0.2.3 \
		hermit-abi-0.1.18 \
		js-sys-0.3.46 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		log-0.4.11 \
		memchr-2.3.4 \
		nix-0.19.1 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.10 \
		redox_users-0.3.5 \
		redox_users-0.4.0 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		rug-1.11.0 \
		rustyline-7.1.0 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		seahorse-1.1.1 \
		serde-1.0.118 \
		syn-1.0.54 \
		test-case-1.0.0 \
		thread_local-1.0.1 \
		toml-0.5.7 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		utf8parse-0.2.0 \
		version_check-0.9.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.69 \
		wasm-bindgen-backend-0.2.69 \
		wasm-bindgen-futures-0.4.19 \
		wasm-bindgen-macro-0.2.69 \
		wasm-bindgen-macro-support-0.2.69 \
		wasm-bindgen-shared-0.2.69 \
		wasm-bindgen-test-0.3.19 \
		wasm-bindgen-test-macro-0.3.19 \
		web-sys-0.3.46 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winres-0.1.11 \
		gmp-mpfr-sys@git+https://gitlab.com/tspiteri/gmp-mpfr-sys.git\#21966f4bfb56c87d407eb14c72e92ef4e55856aa
CARGO_CARGOTOML=	${WRKSRC}/cli/Cargo.toml
CARGO_INSTALL_PATH=	./cli
PLIST_FILES=	bin/kalker

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC_crate_gmp-mpfr-sys}/build.rs

.include <bsd.port.mk>

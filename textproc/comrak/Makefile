PORTNAME=	comrak
DISTVERSION=	0.18.0
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CommonMark + GFM compatible Markdown parser and renderer
WWW=		https://docs.rs/comrak/latest/comrak/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kivikakk

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.20 \
		arbitrary-1.3.0 \
		autocfg-1.1.0 \
		base64-0.13.1 \
		bincode-1.3.3 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		clap-4.0.32 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		crc32fast-1.3.2 \
		derive_arbitrary-1.3.0 \
		deunicode-0.4.3 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		emojis-0.5.2 \
		entities-1.0.1 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fancy-regex-0.7.1 \
		fastrand-1.8.0 \
		flate2-1.0.25 \
		fnv-1.0.7 \
		getrandom-0.1.16 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.2.6 \
		indexmap-1.9.2 \
		instant-0.1.12 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.2 \
		itoa-1.0.5 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.1.4 \
		memchr-2.5.0 \
		miniz_oxide-0.6.2 \
		ntest-0.9.0 \
		ntest_test_cases-0.9.0 \
		ntest_timeout-0.9.0 \
		num-traits-0.2.15 \
		once_cell-1.17.0 \
		onig-6.4.0 \
		onig_sys-69.8.1 \
		os_str_bytes-6.4.1 \
		phf-0.11.1 \
		phf_shared-0.11.1 \
		pkg-config-0.3.26 \
		plist-1.3.1 \
		ppv-lite86-0.2.17 \
		proc-macro-crate-1.2.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.49 \
		propfuzz-0.0.1 \
		propfuzz-macro-0.0.1 \
		proptest-0.10.1 \
		quick-error-1.2.3 \
		quote-1.0.23 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_xorshift-0.2.0 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.0 \
		regex-syntax-0.6.28 \
		rustix-0.36.6 \
		rusty-fork-0.3.0 \
		ryu-1.0.12 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		serde_json-1.0.91 \
		shell-words-1.1.0 \
		siphasher-0.3.10 \
		slug-0.1.4 \
		strsim-0.10.0 \
		syn-1.0.107 \
		syntect-5.0.0 \
		tempfile-3.4.0 \
		termcolor-1.1.3 \
		terminal_size-0.2.3 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		time-0.3.17 \
		time-core-0.1.0 \
		time-macros-0.2.6 \
		toml-0.5.10 \
		typed-arena-2.0.1 \
		unicode-ident-1.0.6 \
		unicode_categories-0.1.1 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0 \
		xdg-2.4.1 \
		xml-rs-0.8.4 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

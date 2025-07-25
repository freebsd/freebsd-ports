PORTNAME=	tokay
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.10
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming language designed for ad-hoc parsing, inspired by awk
WWW=		https://tokay.dev \
		https://github.com/tokay-lang/tokay

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tokay-lang

CARGO_CRATES=	aho-corasick-1.1.3 \
		ansi_term-0.12.1 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.7 \
		atty-0.2.14 \
		autocfg-1.4.0 \
		bitflags-1.2.1 \
		bitflags-2.8.0 \
		cc-1.2.15 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		charclass-0.3.0 \
		clap-2.34.0 \
		clap-4.5.31 \
		clap_builder-4.5.31 \
		clap_derive-4.5.28 \
		clap_lex-0.7.4 \
		clipboard-win-4.5.0 \
		clipboard-win-5.4.0 \
		colorchoice-1.0.3 \
		ctor-0.1.26 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		endian-type-0.1.2 \
		env_filter-0.1.3 \
		env_logger-0.11.6 \
		equivalent-1.0.2 \
		errno-0.3.10 \
		error-code-2.3.1 \
		error-code-3.3.1 \
		fd-lock-2.0.0 \
		fd-lock-4.0.2 \
		getrandom-0.2.15 \
		ghost-0.1.18 \
		glob-0.3.2 \
		hashbrown-0.15.2 \
		heck-0.5.0 \
		hermit-abi-0.1.19 \
		home-0.5.11 \
		humantime-2.1.0 \
		indexmap-2.7.1 \
		inventory-0.1.11 \
		inventory-impl-0.1.11 \
		is_terminal_polyfill-1.70.1 \
		libc-0.2.170 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.15 \
		log-0.4.26 \
		memchr-2.7.4 \
		memoffset-0.6.5 \
		nibble_vec-0.1.0 \
		nix-0.20.2 \
		nix-0.29.0 \
		num-0.4.3 \
		num-bigint-0.4.6 \
		num-complex-0.4.6 \
		num-integer-0.1.46 \
		num-iter-0.1.45 \
		num-parse-0.1.2 \
		num-rational-0.4.2 \
		num-traits-0.2.19 \
		once_cell-1.20.3 \
		proc-macro2-1.0.93 \
		quote-1.0.38 \
		radix_trie-0.2.1 \
		redox_users-0.4.6 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustix-0.38.44 \
		rustyline-8.2.0 \
		rustyline-15.0.0 \
		scopeguard-1.2.0 \
		shlex-1.3.0 \
		smallvec-1.14.0 \
		str-buf-1.0.6 \
		strsim-0.8.0 \
		strsim-0.11.1 \
		syn-1.0.109 \
		syn-2.0.98 \
		textwrap-0.11.0 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		tokay-0.4.0 \
		tokay-macros-0.5.0 \
		unicode-ident-1.0.17 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.1.14 \
		unicode-width-0.2.0 \
		utf8parse-0.2.2 \
		vec_map-0.8.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		yaml-rust-0.3.5

PLIST_FILES=	bin/${PORTNAME}

do-install: # workaround this error in do-install: There are multiple `tokay` packages in your project, and the specification `tokay` is ambiguous.
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/tokay ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

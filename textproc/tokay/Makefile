PORTNAME=	tokay
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming language designed for ad-hoc parsing, inspired by awk
WWW=		https://tokay.dev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tokay-lang

CARGO_CRATES=	aho-corasick-1.1.3 \
		ansi_term-0.12.1 \
		anstream-0.6.13 \
		anstyle-1.0.6 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.2 \
		anstyle-wincon-3.0.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.2.1 \
		bitflags-2.5.0 \
		cc-1.0.90 \
		cfg-if-1.0.0 \
		cfg_aliases-0.1.1 \
		charclass-0.2.0 \
		clap-2.34.0 \
		clap-4.5.3 \
		clap_builder-4.5.2 \
		clap_derive-4.5.3 \
		clap_lex-0.7.0 \
		clipboard-win-4.5.0 \
		clipboard-win-5.3.0 \
		colorchoice-1.0.0 \
		ctor-0.1.26 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		endian-type-0.1.2 \
		env_filter-0.1.0 \
		env_logger-0.11.3 \
		equivalent-1.0.1 \
		errno-0.3.8 \
		error-code-2.3.1 \
		error-code-3.2.0 \
		fd-lock-2.0.0 \
		fd-lock-4.0.2 \
		getrandom-0.2.12 \
		ghost-0.1.17 \
		glob-0.3.1 \
		hashbrown-0.14.3 \
		heck-0.5.0 \
		hermit-abi-0.1.19 \
		home-0.5.9 \
		humantime-2.1.0 \
		indexmap-2.2.5 \
		inventory-0.1.11 \
		inventory-impl-0.1.11 \
		libc-0.2.153 \
		libredox-0.0.1 \
		linux-raw-sys-0.4.13 \
		log-0.4.21 \
		memchr-2.7.1 \
		memoffset-0.6.5 \
		nibble_vec-0.1.0 \
		nix-0.20.2 \
		nix-0.28.0 \
		num-0.4.1 \
		num-bigint-0.4.4 \
		num-complex-0.4.5 \
		num-integer-0.1.46 \
		num-iter-0.1.44 \
		num-parse-0.1.2 \
		num-rational-0.4.1 \
		num-traits-0.2.18 \
		proc-macro2-1.0.79 \
		quote-1.0.35 \
		radix_trie-0.2.1 \
		redox_syscall-0.4.1 \
		redox_users-0.4.4 \
		regex-1.10.3 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.2 \
		rustix-0.38.32 \
		rustyline-8.2.0 \
		rustyline-14.0.0 \
		scopeguard-1.2.0 \
		smallvec-1.13.2 \
		str-buf-1.0.6 \
		strsim-0.8.0 \
		strsim-0.11.0 \
		syn-1.0.109 \
		syn-2.0.53 \
		textwrap-0.11.0 \
		thiserror-1.0.58 \
		thiserror-impl-1.0.58 \
		tokay-0.4.0 \
		tokay-macros-0.5.0 \
		unicode-ident-1.0.12 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.11 \
		utf8parse-0.2.1 \
		vec_map-0.8.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.4 \
		windows_aarch64_gnullvm-0.52.4 \
		windows_aarch64_msvc-0.52.4 \
		windows_i686_gnu-0.52.4 \
		windows_i686_msvc-0.52.4 \
		windows_x86_64_gnu-0.52.4 \
		windows_x86_64_gnullvm-0.52.4 \
		windows_x86_64_msvc-0.52.4 \
		yaml-rust-0.3.5

PLIST_FILES=	bin/${PORTNAME}

do-install: # workaround this error in do-install: There are multiple `tokay` packages in your project, and the specification `tokay` is ambiguous.
	${INSTALL_PROGRAM} ${WRKDIR}/target/*-unknown-freebsd/release/tokay ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

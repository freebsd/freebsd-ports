PORTNAME=	tokay
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming language designed for ad-hoc parsing, inspired by awk
WWW=		https://tokay.dev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tokay-lang

CARGO_CRATES=	ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		charclass-0.2.0 \
		clap-2.34.0 \
		clap-4.0.10 \
		clap_derive-4.0.10 \
		clap_lex-0.3.0 \
		clipboard-win-4.4.1 \
		ctor-0.1.22 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		endian-type-0.1.2 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		error-code-2.3.1 \
		fd-lock-2.0.0 \
		fd-lock-3.0.6 \
		getrandom-0.2.7 \
		ghost-0.1.5 \
		glob-0.3.0 \
		hashbrown-0.12.1 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.9.1 \
		inventory-0.1.11 \
		inventory-impl-0.1.11 \
		io-lifetimes-0.7.3 \
		libc-0.2.134 \
		linux-raw-sys-0.0.46 \
		log-0.4.17 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		nibble_vec-0.1.0 \
		nix-0.20.0 \
		nix-0.23.1 \
		num-0.4.0 \
		num-bigint-0.4.3 \
		num-complex-0.4.2 \
		num-integer-0.1.45 \
		num-iter-0.1.43 \
		num-parse-0.1.1 \
		num-rational-0.4.1 \
		num-traits-0.2.15 \
		once_cell-1.13.0 \
		os_str_bytes-6.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.46 \
		quote-1.0.20 \
		radix_trie-0.2.1 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		rustix-0.35.11 \
		rustyline-8.2.0 \
		rustyline-9.1.2 \
		scopeguard-1.1.0 \
		smallvec-1.9.0 \
		str-buf-1.0.6 \
		strsim-0.8.0 \
		strsim-0.10.0 \
		syn-1.0.98 \
		termcolor-1.1.3 \
		textwrap-0.11.0 \
		thiserror-1.0.31 \
		thiserror-impl-1.0.31 \
		tokay-0.4.0 \
		tokay-macros-0.4.0 \
		unicode-ident-1.0.1 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		utf8parse-0.2.0 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1 \
		yaml-rust-0.3.5

PLIST_FILES=	bin/${PORTNAME}

do-install: # workaround this error in do-install: There are multiple `tokay` packages in your project, and the specification `tokay` is ambiguous.
	${INSTALL_PROGRAM} ${WRKDIR}/target/*-unknown-freebsd/release/tokay ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

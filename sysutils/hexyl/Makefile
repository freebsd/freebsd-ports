PORTNAME=	hexyl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	sysutils

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Command-line hex viewer
WWW=		https://github.com/sharkdp/hexyl

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	aho-corasick-0.7.20 \
		anyhow-1.0.66 \
		assert_cmd-2.0.7 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-1.0.1 \
		cc-1.0.77 \
		clap-4.0.29 \
		clap_lex-0.3.0 \
		const_format-0.2.30 \
		const_format_proc_macros-0.2.29 \
		ctor-0.1.26 \
		diff-0.1.13 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.8.0 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		float-cmp-0.9.0 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.1 \
		is_ci-1.1.1 \
		itertools-0.10.5 \
		libc-0.2.138 \
		linux-raw-sys-0.1.3 \
		memchr-2.5.0 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.15 \
		once_cell-1.16.0 \
		os_str_bytes-6.4.1 \
		output_vt100-0.1.3 \
		owo-colors-3.5.0 \
		predicates-2.1.4 \
		predicates-core-1.0.5 \
		predicates-tree-1.0.7 \
		pretty_assertions-1.3.0 \
		proc-macro2-1.0.47 \
		quote-1.0.21 \
		regex-1.7.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		rustix-0.36.5 \
		serde-1.0.149 \
		strsim-0.10.0 \
		supports-color-1.3.1 \
		syn-1.0.105 \
		termcolor-1.1.3 \
		terminal_size-0.2.3 \
		termtree-0.4.0 \
		thiserror-1.0.37 \
		thiserror-impl-1.0.37 \
		unicode-ident-1.0.5 \
		unicode-xid-0.2.4 \
		wait-timeout-0.2.0 \
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
		yansi-0.5.1

PLIST_FILES=	bin/hexyl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexyl

.include <bsd.port.mk>

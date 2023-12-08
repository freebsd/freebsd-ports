PORTNAME=	difftastic
DISTVERSION=	0.52.0
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Diff tool that compares files based on their syntax
WWW=		https://difftastic.wilfred.me.uk/ \
		https://github.com/Wilfred/difftastic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	Wilfred

PLIST_FILES=	bin/difft

CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-0.7.20 \
		assert_cmd-2.0.5 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.11.1 \
		bytecount-0.6.2 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		clap-3.1.18 \
		clap_lex-0.2.0 \
		const_format-0.2.23 \
		const_format_proc_macros-0.2.22 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		crossterm-0.26.1 \
		crossterm_winapi-0.9.0 \
		ctor-0.1.22 \
		diff-0.1.12 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		env_logger-0.7.1 \
		fixedbitset-0.4.1 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		getrandom-0.2.9 \
		glob-0.3.1 \
		hashbrown-0.11.2 \
		hashbrown-0.12.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		humansize-2.1.3 \
		humantime-1.3.0 \
		indexmap-1.7.0 \
		itertools-0.10.3 \
		itertools-0.11.0 \
		itoa-1.0.9 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		libm-0.2.7 \
		libmimalloc-sys-0.1.24 \
		line-numbers-0.2.2 \
		lock_api-0.4.9 \
		log-0.4.17 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		mimalloc-0.1.28 \
		minimal-lexical-0.2.1 \
		mio-0.8.5 \
		nom-7.1.1 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		once_cell-1.17.1 \
		os_str_bytes-6.0.1 \
		output_vt100-0.1.3 \
		owo-colors-3.5.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.6 \
		petgraph-0.6.1 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		pretty_assertions-1.3.0 \
		pretty_env_logger-0.4.0 \
		proc-macro2-1.0.66 \
		quick-error-1.2.3 \
		quote-1.0.32 \
		radix-heap-0.4.2 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		redox_syscall-0.2.16 \
		regex-1.7.3 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.29 \
		rustc-hash-1.1.0 \
		rustversion-1.0.12 \
		ryu-1.0.15 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.176 \
		serde_derive-1.0.176 \
		serde_json-1.0.104 \
		signal-hook-0.3.14 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		smallvec-1.10.0 \
		strsim-0.10.0 \
		strum-0.25.0 \
		strum_macros-0.25.1 \
		syn-1.0.95 \
		syn-2.0.27 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		textwrap-0.15.0 \
		tree-sitter-0.20.9 \
		typed-arena-2.0.2 \
		unicode-ident-1.0.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.3 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1 \
		wu-diff-0.1.2 \
		yansi-0.5.1 \
		tree_magic_mini@git+https://github.com/Wilfred/tree_magic?branch=fix-panic-for-empty-strings\#13dd6dda15c7062bd8f7dd5bc9bb5b16ce9ee613

PORTSCOUT=	ignore:1

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/difft

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/manual/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/manual

.include <bsd.port.mk>

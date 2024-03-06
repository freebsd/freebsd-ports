PORTNAME=	difftastic
DISTVERSION=	0.56.1
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

CARGO_CRATES=	ahash-0.8.9 \
		aho-corasick-1.1.2 \
		allocator-api2-0.2.16 \
		assert_cmd-2.0.5 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.4.2 \
		bstr-0.2.17 \
		bstr-1.6.0 \
		bumpalo-3.14.0 \
		bytecount-0.6.2 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		clap-3.2.25 \
		clap_lex-0.2.4 \
		const_format-0.2.23 \
		const_format_proc_macros-0.2.22 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		ctor-0.1.22 \
		diff-0.1.12 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		env_logger-0.10.0 \
		errno-0.3.5 \
		fixedbitset-0.4.1 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		glob-0.3.1 \
		globset-0.4.13 \
		hashbrown-0.11.2 \
		hashbrown-0.14.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		hermit-abi-0.3.3 \
		humansize-2.1.3 \
		humantime-2.1.0 \
		ignore-0.4.18 \
		indexmap-1.7.0 \
		io-lifetimes-1.0.11 \
		is-terminal-0.4.7 \
		itertools-0.10.3 \
		itertools-0.11.0 \
		itoa-1.0.9 \
		lazy_static-1.4.0 \
		libc-0.2.149 \
		libm-0.2.7 \
		libmimalloc-sys-0.1.24 \
		line-numbers-0.3.0 \
		linux-raw-sys-0.3.8 \
		lock_api-0.4.11 \
		log-0.4.17 \
		memchr-2.7.1 \
		memoffset-0.6.5 \
		mimalloc-0.1.28 \
		minimal-lexical-0.2.1 \
		mio-0.8.10 \
		nom-7.1.1 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		once_cell-1.19.0 \
		os_str_bytes-6.0.1 \
		output_vt100-0.1.3 \
		owo-colors-3.5.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		petgraph-0.6.1 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		pretty_assertions-1.3.0 \
		pretty_env_logger-0.5.0 \
		proc-macro2-1.0.78 \
		quote-1.0.35 \
		radix-heap-0.4.2 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		redox_syscall-0.4.1 \
		regex-1.9.6 \
		regex-automata-0.1.10 \
		regex-automata-0.3.9 \
		regex-syntax-0.7.5 \
		rustc-hash-1.1.0 \
		rustix-0.37.27 \
		rustversion-1.0.12 \
		ryu-1.0.15 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.176 \
		serde_derive-1.0.176 \
		serde_json-1.0.104 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.1 \
		smallvec-1.13.1 \
		strsim-0.10.0 \
		strum-0.25.0 \
		strum_macros-0.25.1 \
		syn-1.0.95 \
		syn-2.0.49 \
		termcolor-1.1.3 \
		terminal_size-0.2.6 \
		termtree-0.2.4 \
		textwrap-0.16.1 \
		thread_local-1.1.7 \
		tree-sitter-0.20.10 \
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
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		wu-diff-0.1.2 \
		yansi-0.5.1 \
		zerocopy-0.7.32 \
		zerocopy-derive-0.7.32 \
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

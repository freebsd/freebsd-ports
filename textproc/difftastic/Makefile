PORTNAME=	difftastic
DISTVERSION=	0.26.3
CATEGORIES=	textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Diff tool that compares files based on their syntax

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cpe
USE_GITHUB=	yes
GH_ACCOUNT=	Wilfred

PLIST_FILES=	bin/difft

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		archery-0.4.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		clap-3.0.13 \
		const_format-0.2.22 \
		const_format_proc_macros-0.2.22 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.7 \
		ctor-0.1.21 \
		diff-0.1.12 \
		either-1.6.1 \
		env_logger-0.7.1 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		humantime-1.3.0 \
		indexmap-1.8.0 \
		itertools-0.10.3 \
		lazy_static-1.4.0 \
		libc-0.2.112 \
		libmimalloc-sys-0.1.23 \
		log-0.4.14 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		mimalloc-0.1.27 \
		num_cpus-1.13.1 \
		os_str_bytes-6.0.0 \
		output_vt100-0.1.2 \
		owo-colors-3.2.0 \
		pretty_assertions-1.0.0 \
		pretty_env_logger-0.4.0 \
		proc-macro2-1.0.36 \
		quick-error-1.2.3 \
		quote-1.0.13 \
		radix-heap-0.4.2 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rpds-0.10.0 \
		rustc-hash-1.1.0 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.84 \
		term_size-0.3.2 \
		termcolor-1.1.2 \
		textwrap-0.14.2 \
		tree-sitter-0.20.5 \
		typed-arena-2.0.1 \
		unicode-xid-0.2.2 \
		walkdir-2.3.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wu-diff-0.1.2

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/difft

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/manual/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/manual

.include <bsd.port.mk>

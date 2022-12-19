PORTNAME=	bottom
DISTVERSION=	0.6.8-r20220909
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Graphical process and system monitor
WWW=		https://github.com/ClementTsang/bottom

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ClementTsang
GH_TAGNAME=	7218918

PORTDOCS=	*
PLIST_FILES=	bin/btm \
		man/man1/btm.1.gz \
		share/bash-completion/completions/btm.bash \
		share/fish/vendor_completions.d/btm.fish \
		share/zsh/site-functions/_btm

OPTIONS_DEFINE=	DOCS

# Build manpages and shell completion
CARGO_ENV+= 	BTM_GENERATE=true

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		aho-corasick-0.7.18 \
		anyhow-1.0.57 \
		assert_cmd-2.0.4 \
		async-channel-1.6.1 \
		async-executor-1.4.1 \
		async-fs-1.5.0 \
		async-io-1.6.0 \
		async-lock-2.5.0 \
		async-net-1.6.1 \
		async-process-1.3.0 \
		async-task-4.2.0 \
		atomic-waker-1.0.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.65 \
		bitflags-1.3.2 \
		blocking-1.2.0 \
		bstr-0.2.17 \
		byteorder-1.4.3 \
		cache-padded-1.2.0 \
		cargo-husky-1.5.0 \
		cassowary-0.3.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-3.1.12 \
		clap_complete-3.1.2 \
		clap_lex-0.1.1 \
		clap_mangen-0.1.6 \
		concat-string-1.0.1 \
		concurrent-queue-1.2.2 \
		core-foundation-0.7.0 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.7.0 \
		core-foundation-sys-0.8.3 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		crossterm-0.18.2 \
		crossterm_winapi-0.6.2 \
		ctrlc-3.2.2 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		difflib-0.4.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		event-listener-2.5.2 \
		fastrand-1.7.0 \
		fern-0.6.1 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-lite-1.12.0 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-timer-3.0.2 \
		futures-util-0.3.21 \
		fxhash-0.2.1 \
		getrandom-0.2.6 \
		gimli-0.26.1 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		heim-0.1.0-rc.1 \
		heim-common-0.1.0-rc.1 \
		heim-cpu-0.1.0-rc.1 \
		heim-disk-0.1.0-rc.1 \
		heim-memory-0.1.0-rc.1 \
		heim-net-0.1.0-rc.1 \
		heim-runtime-0.1.0-rc.1 \
		heim-sensors-0.1.0-rc.1 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		ident_case-1.0.1 \
		indexmap-1.8.1 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.124 \
		libloading-0.6.7 \
		lock_api-0.4.7 \
		log-0.4.16 \
		macaddr-1.0.1 \
		mach-0.3.2 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		miniz_oxide-0.5.1 \
		mio-0.7.14 \
		miow-0.3.7 \
		nix-0.19.1 \
		nix-0.23.1 \
		nix-0.24.1 \
		normalize-line-endings-0.3.0 \
		ntapi-0.3.7 \
		num-integer-0.1.44 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		num_threads-0.1.5 \
		nvml-wrapper-0.7.0 \
		nvml-wrapper-sys-0.5.0 \
		object-0.28.3 \
		once_cell-1.5.2 \
		os_str_bytes-6.0.0 \
		parking-2.0.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		polling-2.2.0 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro2-1.0.37 \
		procfs-0.12.0 \
		quote-1.0.18 \
		rayon-1.5.2 \
		rayon-core-1.9.2 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		roff-0.2.1 \
		rustc-demangle-0.1.21 \
		ryu-1.0.10 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.82 \
		signal-hook-0.1.17 \
		signal-hook-0.3.13 \
		signal-hook-registry-1.4.0 \
		slab-0.4.6 \
		smallvec-1.8.0 \
		smol-1.2.5 \
		socket2-0.4.4 \
		starship-battery-0.7.9 \
		static_assertions-1.1.0 \
		strsim-0.9.3 \
		strsim-0.10.0 \
		syn-1.0.91 \
		sysctl-0.4.6 \
		sysinfo-0.23.10 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		textwrap-0.15.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.3.9 \
		time-macros-0.2.4 \
		toml-0.5.9 \
		tui-0.14.0 \
		typed-builder-0.10.0 \
		typenum-1.15.0 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		uom-0.30.0 \
		wait-timeout-0.2.0 \
		waker-fn-1.1.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wepoll-ffi-0.1.2 \
		widestring-0.4.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wrapcenum-derive-0.4.0

GEN_DIR= 	${WRKDIR}/bottom-*/target/tmp/bottom
post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/btm
	${INSTALL_MAN} ${GEN_DIR}/manpage/btm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${GEN_DIR}/completion/btm.bash ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${GEN_DIR}/completion/btm.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${GEN_DIR}/completion/_btm     ${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/content && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

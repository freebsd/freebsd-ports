PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.19.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Conveniently learn about the disk usage of directories
WWW=		https://github.com/Byron/dua-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	anyhow-1.0.66 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		byte-unit-4.0.18 \
		cassowary-0.3.0 \
		cc-1.0.77 \
		cfg-if-1.0.0 \
		clap-4.0.29 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		crossbeam-0.8.2 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.13 \
		crossbeam-queue-0.3.8 \
		crossbeam-utils-0.8.14 \
		crossterm-0.25.0 \
		crossterm_winapi-0.9.0 \
		crosstermion-0.10.1 \
		ctor-0.1.26 \
		diff-0.1.13 \
		either-1.8.0 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		filesize-0.2.0 \
		fixedbitset-0.4.2 \
		form_urlencoded-1.1.0 \
		glob-0.3.0 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		idna-0.3.0 \
		indexmap-1.9.2 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.1 \
		itertools-0.10.5 \
		jwalk-0.6.2 \
		libc-0.2.138 \
		linux-raw-sys-0.1.4 \
		lock_api-0.4.9 \
		log-0.4.17 \
		malloc_buf-0.0.6 \
		memoffset-0.7.1 \
		mio-0.8.5 \
		num_cpus-1.14.0 \
		numtoa-0.1.0 \
		objc-0.2.7 \
		once_cell-1.16.0 \
		open-3.2.0 \
		os_str_bytes-6.4.1 \
		output_vt100-0.1.3 \
		owo-colors-3.5.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.5 \
		pathdiff-0.2.1 \
		percent-encoding-2.2.0 \
		petgraph-0.6.2 \
		pretty_assertions-1.3.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.47 \
		quote-1.0.21 \
		rayon-1.6.1 \
		rayon-core-1.10.1 \
		redox_syscall-0.2.16 \
		redox_termios-0.1.2 \
		rustix-0.36.5 \
		scopeguard-1.1.0 \
		serde-1.0.150 \
		signal-hook-0.3.14 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		smallvec-1.10.0 \
		strsim-0.10.0 \
		syn-1.0.105 \
		termcolor-1.1.3 \
		termion-1.5.6 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		trash-3.0.0 \
		tui-0.19.0 \
		tui-react-0.19.0 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.5 \
		unicode-normalization-0.1.22 \
		unicode-segmentation-1.10.0 \
		unicode-width-0.1.10 \
		url-2.3.1 \
		utf8-width-0.1.6 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wild-2.1.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.43.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0 \
		yansi-0.5.1
CARGO_FEATURES=	--no-default-features tui-crossplatform

PLIST_FILES=	bin/dua
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dua

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.18.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Conveniently learn about the disk usage of directories
WWW=		https://github.com/Byron/dua-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	ansi_term-0.12.1 \
		anyhow-1.0.58 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		byte-unit-4.0.14 \
		cassowary-0.3.0 \
		cfg-if-1.0.0 \
		clap-3.2.8 \
		clap_derive-3.2.7 \
		clap_lex-0.2.4 \
		colored-2.0.0 \
		core-foundation-sys-0.8.3 \
		crossbeam-0.8.1 \
		crossbeam-channel-0.5.5 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.9 \
		crossbeam-queue-0.3.5 \
		crossbeam-utils-0.8.10 \
		crossterm-0.25.0 \
		crossterm_winapi-0.9.0 \
		crosstermion-0.10.1 \
		ctor-0.1.22 \
		diff-0.1.13 \
		either-1.7.0 \
		filesize-0.2.0 \
		fixedbitset-0.4.2 \
		form_urlencoded-1.0.1 \
		glob-0.3.0 \
		hashbrown-0.12.1 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		indexmap-1.9.1 \
		itertools-0.10.3 \
		jwalk-0.6.0 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		lock_api-0.4.7 \
		log-0.4.17 \
		malloc_buf-0.0.6 \
		matches-0.1.9 \
		memoffset-0.6.5 \
		mio-0.8.4 \
		ntapi-0.3.7 \
		num_cpus-1.13.1 \
		numtoa-0.1.0 \
		objc-0.2.7 \
		once_cell-1.13.0 \
		open-3.0.1 \
		os_str_bytes-6.1.0 \
		output_vt100-0.1.3 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		pathdiff-0.2.1 \
		percent-encoding-2.1.0 \
		petgraph-0.6.2 \
		pretty_assertions-1.2.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.40 \
		quote-1.0.20 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		redox_syscall-0.2.13 \
		redox_termios-0.1.2 \
		scopeguard-1.1.0 \
		signal-hook-0.3.14 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		smallvec-1.9.0 \
		strsim-0.10.0 \
		syn-1.0.98 \
		sysinfo-0.23.13 \
		termcolor-1.1.3 \
		termion-1.5.6 \
		textwrap-0.15.0 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		trash-2.1.5 \
		tui-0.19.0 \
		tui-react-0.19.0 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.1 \
		unicode-normalization-0.1.21 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		url-2.2.2 \
		utf8-width-0.1.6 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.37.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_aarch64_msvc-0.37.0 \
		windows_i686_gnu-0.36.1 \
		windows_i686_gnu-0.37.0 \
		windows_i686_msvc-0.36.1 \
		windows_i686_msvc-0.37.0 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_gnu-0.37.0 \
		windows_x86_64_msvc-0.36.1 \
		windows_x86_64_msvc-0.37.0
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

PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.16.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Conveniently learn about the disk usage of directories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	ansi_term-0.12.1 \
		anyhow-1.0.52 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		byte-unit-4.0.13 \
		cassowary-0.3.0 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-3.0.0-rc.8 \
		clap_derive-3.0.0-rc.8 \
		colored-2.0.0 \
		const-sha1-0.2.0 \
		core-foundation-sys-0.8.3 \
		crossbeam-0.8.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.5 \
		crossbeam-queue-0.3.2 \
		crossbeam-utils-0.8.5 \
		crossterm-0.20.0 \
		crossterm_winapi-0.8.0 \
		crosstermion-0.8.1 \
		ctor-0.1.21 \
		diff-0.1.12 \
		either-1.6.1 \
		filesize-0.2.0 \
		fixedbitset-0.4.0 \
		form_urlencoded-1.0.1 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		indexmap-1.7.0 \
		instant-0.1.12 \
		itertools-0.10.3 \
		jwalk-0.6.0 \
		lazy_static-1.4.0 \
		libc-0.2.112 \
		lock_api-0.4.5 \
		log-0.4.14 \
		malloc_buf-0.0.6 \
		matches-0.1.9 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		mio-0.7.14 \
		miow-0.3.7 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		numtoa-0.1.0 \
		objc-0.2.7 \
		once_cell-1.9.0 \
		open-2.0.2 \
		os_str_bytes-6.0.0 \
		output_vt100-0.1.2 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		pathdiff-0.2.1 \
		percent-encoding-2.1.0 \
		petgraph-0.6.0 \
		pretty_assertions-1.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.35 \
		quote-1.0.10 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.10 \
		redox_termios-0.1.2 \
		scopeguard-1.1.0 \
		signal-hook-0.3.13 \
		signal-hook-mio-0.2.1 \
		signal-hook-registry-1.4.0 \
		smallvec-1.7.0 \
		strsim-0.10.0 \
		syn-1.0.84 \
		sysinfo-0.22.3 \
		termcolor-1.1.2 \
		termion-1.5.6 \
		textwrap-0.14.2 \
		time-0.1.44 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		trash-2.0.3 \
		tui-0.16.0 \
		tui-react-0.16.0 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		utf8-width-0.1.5 \
		version_check-0.9.3 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.9.1 \
		windows_gen-0.9.1 \
		windows_macros-0.9.1
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

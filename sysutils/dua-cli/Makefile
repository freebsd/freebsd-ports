# $FreeBSD$

PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.1
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Conveniently learn about the disk usage of directories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.31 \
		arc-swap-0.4.7 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		byte-unit-4.0.8 \
		cassowary-0.3.0 \
		cfg-if-0.1.10 \
		clap-2.33.1 \
		cloudabi-0.0.3 \
		colored-1.9.3 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.2 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.7.2 \
		crossterm-0.17.5 \
		crossterm_winapi-0.6.1 \
		crosstermion-0.1.4 \
		ctor-0.1.15 \
		difference-2.0.0 \
		either-1.5.3 \
		filesize-0.2.0 \
		fixedbitset-0.2.0 \
		flume-0.7.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.3.0 \
		heck-0.3.1 \
		hermit-abi-0.1.15 \
		indexmap-1.4.0 \
		iovec-0.1.4 \
		itertools-0.9.0 \
		jwalk-0.5.1 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.71 \
		lock_api-0.3.4 \
		log-0.4.8 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.5 \
		mio-0.6.22 \
		miow-0.2.1 \
		net2-0.2.34 \
		num_cpus-1.13.0 \
		numtoa-0.1.0 \
		open-1.4.0 \
		output_vt100-0.1.2 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		petgraph-0.5.1 \
		pretty_assertions-0.6.1 \
		proc-macro-error-1.0.3 \
		proc-macro-error-attr-1.0.3 \
		proc-macro2-1.0.18 \
		quote-1.0.7 \
		rayon-1.3.1 \
		rayon-core-1.7.1 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		scopeguard-1.1.0 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.0 \
		slab-0.4.2 \
		smallvec-1.4.0 \
		spin-0.5.2 \
		strsim-0.8.0 \
		structopt-0.3.15 \
		structopt-derive-0.4.8 \
		syn-1.0.33 \
		syn-mid-0.5.0 \
		termion-1.5.5 \
		textwrap-0.11.0 \
		tui-0.9.5 \
		tui-react-0.4.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		utf8-width-0.1.3 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wild-2.0.4 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/dua
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dua

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

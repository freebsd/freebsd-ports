# $FreeBSD$

PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Conveniently learn about the disk usage of directories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.33 \
		arc-swap-0.4.7 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byte-unit-4.0.9 \
		cassowary-0.3.0 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		colored-2.0.0 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.4 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.7.2 \
		crossterm-0.17.7 \
		crossterm_winapi-0.6.1 \
		crosstermion-0.4.0 \
		ctor-0.1.16 \
		difference-2.0.0 \
		either-1.6.1 \
		filesize-0.2.0 \
		fixedbitset-0.2.0 \
		glob-0.3.0 \
		hashbrown-0.9.1 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		indexmap-1.6.0 \
		itertools-0.9.0 \
		jwalk-0.5.1 \
		lazy_static-1.4.0 \
		libc-0.2.79 \
		lock_api-0.3.4 \
		log-0.4.11 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.6 \
		mio-0.7.3 \
		miow-0.3.5 \
		ntapi-0.3.4 \
		num_cpus-1.13.0 \
		numtoa-0.1.0 \
		open-1.4.0 \
		output_vt100-0.1.2 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		petgraph-0.5.1 \
		pretty_assertions-0.6.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		rayon-1.4.1 \
		rayon-core-1.8.1 \
		redox_syscall-0.1.57 \
		redox_termios-0.1.1 \
		scopeguard-1.1.0 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.1 \
		smallvec-1.4.2 \
		socket2-0.3.15 \
		strsim-0.8.0 \
		structopt-0.3.20 \
		structopt-derive-0.4.13 \
		syn-1.0.44 \
		termion-1.5.5 \
		textwrap-0.11.0 \
		tui-0.12.0 \
		tui-react-0.12.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		utf8-width-0.1.4 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/dua
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dua

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.5
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Conveniently learn about the disk usage of directories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.34 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byte-unit-4.0.9 \
		cassowary-0.3.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-3.0.0-beta.2 \
		clap_derive-3.0.0-beta.2 \
		cloudabi-0.1.0 \
		colored-2.0.0 \
		const_fn-0.4.3 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.4 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.7.3 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.8.2 \
		crossbeam-epoch-0.9.0 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.7.2 \
		crossbeam-utils-0.8.0 \
		crossterm-0.18.2 \
		crossterm_winapi-0.6.2 \
		crosstermion-0.5.0 \
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
		instant-0.1.8 \
		itertools-0.9.0 \
		jwalk-0.5.1 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		lock_api-0.4.1 \
		log-0.4.11 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.6 \
		mio-0.7.5 \
		miow-0.3.5 \
		ntapi-0.3.6 \
		num_cpus-1.13.0 \
		numtoa-0.1.0 \
		open-1.4.0 \
		os_str_bytes-2.4.0 \
		output_vt100-0.1.2 \
		parking_lot-0.11.0 \
		parking_lot_core-0.8.0 \
		petgraph-0.5.1 \
		pretty_assertions-0.6.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		redox_syscall-0.1.57 \
		redox_termios-0.1.1 \
		scopeguard-1.1.0 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.2 \
		smallvec-1.4.2 \
		socket2-0.3.16 \
		strsim-0.10.0 \
		syn-1.0.48 \
		termcolor-1.1.0 \
		termion-1.5.5 \
		textwrap-0.12.1 \
		tui-0.13.0 \
		tui-react-0.13.0 \
		unicode-segmentation-1.7.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		utf8-width-0.1.4 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
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

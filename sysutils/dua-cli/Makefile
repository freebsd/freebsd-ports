# $FreeBSD$

PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.1
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Conveniently learn about the disk usage of directories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.38 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byte-unit-4.0.9 \
		cassowary-0.3.0 \
		cfg-if-1.0.0 \
		clap-3.0.0-beta.2 \
		clap_derive-3.0.0-beta.2 \
		colored-2.0.0 \
		const_fn-0.4.5 \
		crossbeam-0.8.0 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.1 \
		crossbeam-queue-0.3.1 \
		crossbeam-utils-0.8.1 \
		crossterm-0.18.2 \
		crossterm_winapi-0.6.2 \
		crosstermion-0.6.0 \
		ctor-0.1.19 \
		difference-2.0.0 \
		either-1.6.1 \
		filesize-0.2.0 \
		fixedbitset-0.2.0 \
		glob-0.3.0 \
		hashbrown-0.9.1 \
		heck-0.3.2 \
		hermit-abi-0.1.18 \
		indexmap-1.6.1 \
		instant-0.1.9 \
		itertools-0.10.0 \
		jwalk-0.6.0 \
		lazy_static-1.4.0 \
		libc-0.2.86 \
		lock_api-0.4.2 \
		log-0.4.14 \
		memoffset-0.6.1 \
		mio-0.7.7 \
		miow-0.3.6 \
		ntapi-0.3.6 \
		num_cpus-1.13.0 \
		numtoa-0.1.0 \
		open-1.4.0 \
		os_str_bytes-2.4.0 \
		output_vt100-0.1.2 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		petgraph-0.5.1 \
		pretty_assertions-0.6.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.24 \
		quote-1.0.9 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		redox_syscall-0.2.5 \
		redox_termios-0.1.2 \
		scopeguard-1.1.0 \
		signal-hook-0.1.17 \
		signal-hook-registry-1.3.0 \
		smallvec-1.6.1 \
		socket2-0.3.19 \
		strsim-0.10.0 \
		syn-1.0.60 \
		termcolor-1.1.2 \
		termion-1.5.6 \
		textwrap-0.12.1 \
		tui-0.14.0 \
		tui-react-0.14.0 \
		unicode-segmentation-1.7.1 \
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

# $FreeBSD$

PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Conveniently learn about the disk usage of directories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

CARGO_CRATES=	addr2line-0.12.1 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		backtrace-0.3.48 \
		bitflags-1.2.1 \
		byte-unit-3.1.3 \
		cassowary-0.3.0 \
		cfg-if-0.1.10 \
		clap-2.33.1 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.2 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.2 \
		crossbeam-utils-0.7.2 \
		ctor-0.1.14 \
		difference-2.0.0 \
		either-1.5.3 \
		failure-0.1.8 \
		failure-tools-4.0.5 \
		failure_derive-0.1.8 \
		filesize-0.2.0 \
		fixedbitset-0.2.0 \
		flume-0.7.1 \
		gimli-0.21.0 \
		heck-0.3.1 \
		hermit-abi-0.1.13 \
		indexmap-1.3.2 \
		itertools-0.9.0 \
		jwalk-0.5.1 \
		lazy_static-1.4.0 \
		libc-0.2.71 \
		log-0.4.8 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.4 \
		num_cpus-1.13.0 \
		numtoa-0.1.0 \
		object-0.19.0 \
		open-1.4.0 \
		output_vt100-0.1.2 \
		petgraph-0.5.1 \
		pretty_assertions-0.6.1 \
		proc-macro-error-1.0.2 \
		proc-macro-error-attr-1.0.2 \
		proc-macro2-1.0.17 \
		quote-1.0.6 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		rustc-demangle-0.1.16 \
		scopeguard-1.1.0 \
		spin-0.5.2 \
		strsim-0.8.0 \
		structopt-0.3.14 \
		structopt-derive-0.4.7 \
		syn-1.0.29 \
		syn-mid-0.5.0 \
		synstructure-0.12.3 \
		termion-1.5.5 \
		textwrap-0.11.0 \
		tui-0.9.5 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		winapi-0.3.8 \
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

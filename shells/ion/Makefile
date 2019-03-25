# $FreeBSD$

PORTNAME=	ion
DISTVERSION=	1.0.5-900
CATEGORIES=	shells
PKGNAMESUFFIX=	-shell

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Modern system shell written in Rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	nodefault
GH_TUPLE=	whitequark:rust-xdg:9b205b3cc5d12dc8678dceebb1b751d0176118db:xdg
USE_GITLAB=	yes
GL_SITE=	https://gitlab.redox-os.org
GL_ACCOUNT=	redox-os
GL_COMMIT=	d0c51989dcf276014d92323611491d5e75b1441e
GL_TUPLE=	redox-os:liner:741f36fb656b878b0036f702f2aa9316647c8b2a:liner \
		redox-os:small:cae182c51b323e87bb3617acd1930ca59d0a6676:small \
		redox-os:syscall:54839d42f495e339062b1d3480415544033d0c0c:syscall \
		redox-os:termion:cd8a90a28736e753c55d911bdb95e216eef0ac0b:termion

CARGO_CRATES=	aho-corasick-0.6.10 \
		ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.14 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		bytecount-0.3.2 \
		byteorder-1.3.1 \
		calculate-0.5.1 \
		cast-0.2.2 \
		cc-1.0.31 \
		cfg-if-0.1.7 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		criterion-0.2.10 \
		criterion-plot-0.3.0 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		csv-1.0.5 \
		csv-core-0.1.5 \
		decimal-2.0.4 \
		dirs-1.0.5 \
		either-1.5.1 \
		errno-dragonfly-0.1.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		gcc-0.3.55 \
		getopts-0.2.18 \
		glob-0.2.11 \
		hashbrown-0.1.8 \
		itertools-0.8.0 \
		itoa-0.4.3 \
		lazy_static-1.3.0 \
		libc-0.2.50 \
		memchr-2.2.0 \
		memoffset-0.2.1 \
		nodrop-0.1.13 \
		num-traits-0.2.6 \
		num_cpus-1.10.0 \
		numtoa-0.1.0 \
		ord_subset-3.1.1 \
		permutate-0.3.2 \
		proc-macro2-0.4.27 \
		quote-0.6.11 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rand_xoshiro-0.1.0 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		rdrand-0.4.0 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		regex-1.1.2 \
		regex-syntax-0.6.5 \
		rustc-demangle-0.1.13 \
		rustc-serialize-0.3.24 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		serde-1.0.89 \
		serde_derive-1.0.89 \
		serde_json-1.0.39 \
		smallvec-0.6.9 \
		strsim-0.7.0 \
		syn-0.15.29 \
		synstructure-0.10.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		tinytemplate-1.0.1 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		users-0.8.1 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		walkdir-2.2.7 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_USE_GITHUB=	yes
CARGO_USE_GITLAB=	yes

CONFLICTS_INSTALL=	ion

OPTIONS_DEFINE=	DOCS EXAMPLES

post-configure:
	${ECHO_CMD} ${GL_COMMIT} > ${WRKSRC}/git_revision.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ion

post-install-DOCS-on:
	@cd ${WRKSRC}/manual/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

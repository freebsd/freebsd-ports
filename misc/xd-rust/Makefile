PORTNAME=	xd
DISTVERSION=	0.0.4
PORTREVISION=	42
CATEGORIES=	misc
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/:main
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:main

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool that dumps binary input in a variety of formats
WWW=		https://bitbucket.org/delan/xd/src/default/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cargo

CARGO_CRATES=	addr2line-0.14.0 \
		adler-0.2.3 \
		aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.1 \
		backtrace-0.3.54 \
		bitflags-1.2.1 \
		cc-1.0.62 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		color-eyre-0.5.7 \
		color-spantrace-0.1.4 \
		eyre-0.6.3 \
		fuchsia-cprng-0.1.1 \
		generator-0.6.23 \
		gimli-0.23.0 \
		hermit-abi-0.1.17 \
		indenter-0.3.0 \
		itoa-0.4.6 \
		jane-eyre-0.3.0 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		log-0.4.11 \
		loom-0.3.6 \
		memchr-2.3.4 \
		miniz_oxide-0.4.3 \
		mktemp-0.4.0 \
		nix-0.19.1 \
		object-0.22.0 \
		once_cell-1.5.2 \
		owo-colors-1.1.3 \
		pin-project-lite-0.1.11 \
		pledge-0.4.0 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		rustc-demangle-0.1.18 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		scoped-tls-1.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.117 \
		serde_derive-1.0.117 \
		serde_json-1.0.59 \
		sharded-slab-0.1.0 \
		strsim-0.8.0 \
		syn-1.0.48 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		tracing-0.1.21 \
		tracing-attributes-0.1.11 \
		tracing-core-0.1.17 \
		tracing-error-0.1.2 \
		tracing-subscriber-0.2.15 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		unveil-0.2.1 \
		uuid-0.7.4 \
		vec_map-0.8.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

BB_ACCOUNT=	delan
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	4bdbb191ed6d

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

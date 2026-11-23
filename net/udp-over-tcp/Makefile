PORTNAME=	udp-over-tcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Proxy UDP traffic over a TCP stream
WWW=		https://github.com/mullvad/udp-over-tcp

LICENSE=	MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	mullvad

CARGO_CRATES=	aho-corasick-1.1.4 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		autocfg-1.5.0 \
		bitflags-2.11.1 \
		bytes-1.11.1 \
		cadence-1.8.0 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		clap-4.6.1 \
		clap_builder-4.6.0 \
		clap_derive-4.6.1 \
		clap_lex-1.1.0 \
		colorchoice-1.0.5 \
		crossbeam-channel-0.5.15 \
		crossbeam-utils-0.8.21 \
		env_filter-1.0.1 \
		env_logger-0.11.10 \
		err-context-0.1.0 \
		futures-0.3.32 \
		futures-channel-0.3.32 \
		futures-core-0.3.32 \
		futures-executor-0.3.32 \
		futures-io-0.3.32 \
		futures-macro-0.3.32 \
		futures-sink-0.3.32 \
		futures-task-0.3.32 \
		futures-util-0.3.32 \
		heck-0.5.0 \
		is_terminal_polyfill-1.70.2 \
		jiff-0.2.24 \
		jiff-static-0.2.24 \
		libc-0.2.186 \
		log-0.4.29 \
		memchr-2.8.0 \
		memoffset-0.9.1 \
		mio-1.2.0 \
		nix-0.31.2 \
		once_cell_polyfill-1.70.2 \
		pin-project-lite-0.2.17 \
		portable-atomic-1.13.1 \
		portable-atomic-util-0.2.7 \
		proc-macro2-1.0.106 \
		quote-1.0.45 \
		regex-1.12.3 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		slab-0.4.12 \
		socket2-0.6.3 \
		strsim-0.11.1 \
		syn-2.0.117 \
		tokio-1.54.1 \
		tokio-macros-2.7.0 \
		unicode-ident-1.0.24 \
		utf8parse-0.2.2 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		windows-link-0.2.1 \
		windows-sys-0.61.2
CARGO_BUILD_ARGS=	--all-features
CARGO_INSTALL_ARGS=	--all-features

BINARIES=	bin/udp2tcp \
		bin/tcp2udp

PLIST_FILES=	${BINARIES}

.include <bsd.port.mk>

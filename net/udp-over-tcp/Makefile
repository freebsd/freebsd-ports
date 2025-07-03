PORTNAME=	udp-over-tcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	11
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Proxy UDP traffic over a TCP stream
WWW=		https://github.com/mullvad/udp-over-tcp

LICENSE=	MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	mullvad

CARGO_CRATES=	addr2line-0.21.0 \
		adler-1.0.2 \
		aho-corasick-1.1.1 \
		anstream-0.6.4 \
		anstyle-1.0.4 \
		anstyle-parse-0.2.2 \
		anstyle-query-1.0.0 \
		anstyle-wincon-3.0.1 \
		autocfg-1.1.0 \
		backtrace-0.3.69 \
		bitflags-2.4.0 \
		bytes-1.5.0 \
		cadence-1.0.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		clap-4.4.6 \
		clap_builder-4.4.6 \
		clap_derive-4.4.2 \
		clap_lex-0.5.1 \
		colorchoice-1.0.0 \
		crossbeam-channel-0.5.8 \
		crossbeam-utils-0.8.16 \
		env_logger-0.10.0 \
		err-context-0.1.0 \
		errno-0.3.4 \
		errno-dragonfly-0.1.2 \
		futures-0.3.28 \
		futures-channel-0.3.28 \
		futures-core-0.3.28 \
		futures-executor-0.3.28 \
		futures-io-0.3.28 \
		futures-macro-0.3.28 \
		futures-sink-0.3.28 \
		futures-task-0.3.28 \
		futures-util-0.3.28 \
		gimli-0.28.0 \
		heck-0.4.1 \
		hermit-abi-0.3.3 \
		humantime-2.1.0 \
		is-terminal-0.4.9 \
		lazy_static-1.4.0 \
		libc-0.2.148 \
		linux-raw-sys-0.4.8 \
		log-0.4.20 \
		memchr-2.6.4 \
		memoffset-0.9.0 \
		miniz_oxide-0.7.1 \
		mio-0.8.8 \
		nix-0.27.1 \
		num_cpus-1.16.0 \
		object-0.32.1 \
		pin-project-lite-0.2.13 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.67 \
		quote-1.0.33 \
		regex-1.9.6 \
		regex-automata-0.3.9 \
		regex-syntax-0.7.5 \
		rustc-demangle-0.1.23 \
		rustix-0.38.17 \
		slab-0.4.9 \
		socket2-0.5.4 \
		strsim-0.10.0 \
		syn-2.0.37 \
		termcolor-1.3.0 \
		tokio-1.32.0 \
		tokio-macros-2.1.0 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5
CARGO_BUILD_ARGS=	--all-features
CARGO_INSTALL_ARGS=	--all-features

BINARIES=	bin/udp2tcp \
		bin/tcp2udp

PLIST_FILES=	${BINARIES}

.include <bsd.port.mk>

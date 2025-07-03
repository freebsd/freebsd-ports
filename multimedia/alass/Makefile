PORTNAME=	alass
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
PORTREVISION=	16
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic Language-Agnostic Subtitle Synchronization
WWW=		https://github.com/kaegi/alass

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	kaegi

WRKSRC_SUBDIR=	alass-cli

CARGO_CRATES=	aho-corasick-0.6.10 \
		ansi_term-0.11.0 \
		ascii-0.7.1 \
		atty-0.2.13 \
		autocfg-0.1.6 \
		backtrace-0.3.38 \
		backtrace-sys-0.1.31 \
		bitflags-1.2.0 \
		byteorder-1.3.2 \
		c2-chacha-0.2.2 \
		cast-0.2.2 \
		cc-1.0.45 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		combine-2.5.2 \
		ctrlc-3.1.3 \
		either-1.5.3 \
		encoding_rs-0.8.20 \
		enum_primitive-0.1.1 \
		error-chain-0.10.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		getrandom-0.1.12 \
		image-0.13.0 \
		itertools-0.8.0 \
		itoa-0.4.4 \
		lazy_static-0.2.11 \
		lazy_static-1.4.0 \
		libc-0.2.62 \
		log-0.3.9 \
		log-0.4.8 \
		memchr-2.2.1 \
		nix-0.14.1 \
		nom-2.1.0 \
		num-integer-0.1.41 \
		num-iter-0.1.39 \
		num-rational-0.1.42 \
		num-traits-0.1.43 \
		num-traits-0.2.8 \
		num_cpus-1.10.1 \
		numtoa-0.1.0 \
		pbr-1.0.2 \
		ppv-lite86-0.2.5 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.4 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.7.2 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		regex-0.2.11 \
		regex-syntax-0.5.6 \
		rmp-0.8.8 \
		rmp-serde-0.14.0 \
		rustc-demangle-0.1.16 \
		ryu-1.0.0 \
		safemem-0.2.0 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		serde_json-1.0.40 \
		strsim-0.8.0 \
		subparse-0.6.2 \
		syn-0.15.44 \
		syn-1.0.5 \
		synstructure-0.10.2 \
		termion-1.5.3 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		threadpool-1.7.1 \
		time-0.1.42 \
		ucd-util-0.1.5 \
		unicode-width-0.1.6 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		utf8-ranges-1.0.4 \
		vec_map-0.8.1 \
		vobsub-0.2.3 \
		void-1.0.2 \
		wasi-0.7.0 \
		webrtc-vad-0.4.0 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}-cli

.include <bsd.port.mk>

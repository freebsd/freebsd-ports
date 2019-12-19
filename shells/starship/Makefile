# $FreeBSD$

PORTNAME=	starship
DISTVERSION=	0.13.1
PORTREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	CRATESIO
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-shell prompt for astronauts

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2
RUN_DEPENDS=	powerline-fonts>0:x11-fonts/powerline-fonts

USES=		cargo ssl

CARGO_CRATES=	\
		aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		ansi_term-0.12.0 \
		arrayref-0.3.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.34 \
		backtrace-sys-0.1.28 \
		base64-0.10.1 \
		battery-0.7.4 \
		bitflags-1.1.0 \
		blake2b_simd-0.5.6 \
		byteorder-1.3.2 \
		c2-chacha-0.2.2 \
		cc-1.0.36 \
		cfg-if-0.1.7 \
		chrono-0.4.6 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crossbeam-deque-0.6.3 \
		crossbeam-epoch-0.7.1 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.5 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		either-1.5.2 \
		env_logger-0.6.2 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		getrandom-0.1.10 \
		git2-0.10.0 \
		humantime-1.2.0 \
		idna-0.2.0 \
		itoa-0.4.4 \
		lazycell-1.2.1 \
		lazy_static-1.4.0 \
		libc-0.2.58 \
		libc-0.2.60 \
		libgit2-sys-0.9.0 \
		libssh2-sys-0.2.11 \
		libz-sys-1.0.25 \
		log-0.4.8 \
		mach-0.2.3 \
		matches-0.1.8 \
		memchr-2.2.0 \
		memoffset-0.2.1 \
		nix-0.14.0 \
		nodrop-0.1.13 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		num_cpus-1.10.0 \
		numtoa-0.1.0 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.46 \
		path-slash-0.1.1 \
		percent-encoding-2.0.0 \
		pkg-config-0.3.14 \
		pretty_env_logger-0.3.1 \
		ppv-lite86-0.2.5 \
		quick-error-1.2.2 \
		quote-0.6.3 \
		rand-0.7.0 \
		rand_core-0.3.1 \
		rand_core-0.5.0 \
		rand_chacha-0.2.1 \
		rand_core-0.4.0 \
		rand_hc-0.2.0 \
		rand_os-0.1.1 \
		rayon-1.1.0 \
		rayon-core-1.5.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		redox_users-0.3.1 \
		regex-1.1.6 \
		regex-syntax-0.6.6 \
		remove_dir_all-0.5.2 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		proc-macro2-0.4.8 \
		ryu-1.0.0 \
		scopeguard-0.3.3 \
		serde-1.0.98 \
		serde_json-1.0.40 \
		smallvec-0.6.10 \
		spin-0.5.0 \
		strsim-0.8.0 \
		syn-0.15.0 \
		synstructure-0.10.0 \
		tempfile-3.1.0 \
		termcolor-1.0.4 \
		termion-1.5.3 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		toml-0.5.3 \
		typenum-1.10.0 \
		ucd-util-0.1.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		uom-0.23.0 \
		url-2.0.0 \
		utf8-ranges-1.0.2 \
		vcpkg-0.2.7 \
		vec_map-0.8.1 \
		void-1.0.2 \
		wasi-0.5.0 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-util-0.1.2 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

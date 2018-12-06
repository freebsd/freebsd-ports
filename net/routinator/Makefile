# $FreeBSD$

PORTNAME=	routinator
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI signed route collector and validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rsync:net/rsync

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		arc-swap-0.3.4 \
		argon2rs-0.2.5 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		backtrace-0.3.9 \
		backtrace-sys-0.1.24 \
		base64-0.9.3 \
		bcder-0.1.0 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		byteorder-1.2.7 \
		bytes-0.4.10 \
		cc-1.0.25 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		crossbeam-deque-0.6.1 \
		crossbeam-epoch-0.5.2 \
		crossbeam-utils-0.5.0 \
		daemonize-0.3.0 \
		dirs-1.0.4 \
		env_logger-0.5.13 \
		error-chain-0.11.0 \
		failure-0.1.3 \
		failure_derive-0.1.3 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.25 \
		futures-cpupool-0.1.8 \
		hex-0.3.2 \
		humantime-1.1.1 \
		iovec-0.1.2 \
		json-0.11.13 \
		kernel32-sys-0.2.2 \
		lazy_static-1.2.0 \
		lazycell-1.2.0 \
		libc-0.2.43 \
		lock_api-0.1.4 \
		log-0.4.6 \
		memchr-2.1.1 \
		memoffset-0.2.1 \
		mio-0.6.16 \
		mio-named-pipes-0.1.6 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		miow-0.3.3 \
		net2-0.2.33 \
		nodrop-0.1.12 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		num_cpus-1.8.0 \
		owning_ref-0.3.3 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.1 \
		proc-macro2-0.4.20 \
		quick-error-1.2.2 \
		quote-0.6.9 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand_core-0.2.2 \
		rand_core-0.3.0 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		redox_users-0.2.0 \
		regex-1.0.6 \
		regex-syntax-0.6.2 \
		ring-0.13.3 \
		rpki-0.1.0 \
		rustc-demangle-0.1.9 \
		rustc_version-0.2.3 \
		safemem-0.3.0 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		signal-hook-0.1.5 \
		slab-0.4.1 \
		smallvec-0.6.5 \
		socket2-0.3.8 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		syn-0.15.18 \
		synstructure-0.10.1 \
		syslog-4.0.1 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		time-0.1.40 \
		tokio-0.1.11 \
		tokio-codec-0.1.1 \
		tokio-current-thread-0.1.3 \
		tokio-executor-0.1.5 \
		tokio-fs-0.1.4 \
		tokio-io-0.1.10 \
		tokio-process-0.2.3 \
		tokio-reactor-0.1.6 \
		tokio-signal-0.2.6 \
		tokio-tcp-0.1.2 \
		tokio-threadpool-0.1.8 \
		tokio-timer-0.2.7 \
		tokio-udp-0.1.2 \
		tokio-uds-0.2.3 \
		ucd-util-0.1.2 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		untrusted-0.6.2 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		ws2_32-sys-0.2.1 \
		xml-rs-0.8.0

PLIST_FILES=	bin/routinator \
		man/man1/routinator.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/routinator
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>

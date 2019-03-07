# $FreeBSD$

PORTNAME=	routinator
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI signed route collector and validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rsync:net/rsync

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs

CARGO_CRATES=	ansi_term-0.11.0 \
		arc-swap-0.3.7 \
		argon2rs-0.2.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.14 \
		backtrace-sys-0.1.28 \
		base64-0.9.3 \
		bcder-0.2.1 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		byteorder-1.3.1 \
		bytes-0.4.11 \
		cc-1.0.30 \
		cfg-if-0.1.7 \
		chrono-0.4.6 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		crossbeam-deque-0.7.1 \
		crossbeam-epoch-0.7.1 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.5 \
		daemonize-0.3.0 \
		derive_more-0.14.0 \
		dirs-1.0.5 \
		error-chain-0.11.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fern-0.5.7 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.25 \
		futures-cpupool-0.1.8 \
		hex-0.3.2 \
		httparse-1.3.3 \
		iovec-0.1.2 \
		json-0.11.13 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		lazycell-1.2.1 \
		libc-0.2.50 \
		lock_api-0.1.5 \
		log-0.4.6 \
		memoffset-0.2.1 \
		mio-0.6.16 \
		mio-named-pipes-0.1.6 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		miow-0.3.3 \
		net2-0.2.33 \
		nodrop-0.1.13 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		num_cpus-1.10.0 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
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
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		remove_dir_all-0.5.1 \
		ring-0.13.5 \
		rpki-0.3.1 \
		rustc-demangle-0.1.13 \
		rustc_version-0.2.3 \
		safemem-0.3.0 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.89 \
		signal-hook-0.1.8 \
		slab-0.4.2 \
		smallvec-0.6.9 \
		socket2-0.3.8 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		syn-0.15.27 \
		synstructure-0.10.1 \
		syslog-4.0.1 \
		tempfile-3.0.7 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		time-0.1.42 \
		tokio-0.1.16 \
		tokio-codec-0.1.1 \
		tokio-current-thread-0.1.5 \
		tokio-executor-0.1.6 \
		tokio-fs-0.1.6 \
		tokio-io-0.1.12 \
		tokio-process-0.2.3 \
		tokio-reactor-0.1.9 \
		tokio-signal-0.2.7 \
		tokio-sync-0.1.3 \
		tokio-tcp-0.1.3 \
		tokio-threadpool-0.1.12 \
		tokio-timer-0.2.10 \
		tokio-udp-0.1.3 \
		tokio-uds-0.2.5 \
		toml-0.4.10 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		untrusted-0.6.2 \
		vec_map-0.8.1 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/routinator \
		man/man1/routinator.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/routinator
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>

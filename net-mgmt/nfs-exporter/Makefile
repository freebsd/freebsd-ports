# $FreeBSD$

PORTNAME=	nfs-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Prometheus exporter for NFS statistics

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Axcient
GH_PROJECT=	freebsd-nfs-exporter
USE_RC_SUBR=	nfs_exporter

CARGO_CRATES=	aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		bytes-0.4.12 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		crossbeam-channel-0.3.9 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.2 \
		either-1.6.0 \
		env_logger-0.7.1 \
		fnv-1.0.7 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.29 \
		futures-cpupool-0.1.8 \
		h2-0.1.26 \
		hashbrown-0.8.2 \
		hermit-abi-0.1.15 \
		http-0.1.21 \
		http-body-0.1.0 \
		httparse-1.3.4 \
		humantime-1.3.0 \
		hyper-0.12.35 \
		indexmap-1.5.2 \
		iovec-0.1.4 \
		itoa-0.4.6 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.76 \
		lock_api-0.3.4 \
		log-0.4.11 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memoffset-0.5.5 \
		mio-0.6.22 \
		miow-0.2.1 \
		net2-0.2.34 \
		num_cpus-1.13.0 \
		parking_lot-0.9.0 \
		parking_lot_core-0.6.2 \
		proc-macro2-1.0.19 \
		prometheus-0.9.0 \
		prometheus_exporter-0.6.1 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		rustc_version-0.2.3 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		slab-0.4.2 \
		smallvec-0.6.13 \
		spin-0.5.2 \
		string-0.2.1 \
		strsim-0.8.0 \
		syn-1.0.39 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.20 \
		thiserror-impl-1.0.20 \
		thread_local-1.0.1 \
		time-0.1.44 \
		tokio-0.1.22 \
		tokio-buf-0.1.1 \
		tokio-current-thread-0.1.7 \
		tokio-executor-0.1.10 \
		tokio-io-0.1.13 \
		tokio-reactor-0.1.12 \
		tokio-sync-0.1.8 \
		tokio-tcp-0.1.4 \
		tokio-threadpool-0.1.18 \
		tokio-timer-0.2.13 \
		try-lock-0.2.3 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		want-0.2.0 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/nfs-exporter

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nfs-exporter

.include <bsd.port.mk>

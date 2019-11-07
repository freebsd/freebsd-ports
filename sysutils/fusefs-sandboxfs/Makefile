# $FreeBSD$

PORTNAME=	sandboxfs
DISTVERSIONPREFIX=	sandboxfs-
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Virtual file system for sandboxing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo fuse
USE_GITHUB=	yes
GH_ACCOUNT=	bazelbuild

CARGO_CRATES=	aho-corasick-0.7.6 \
		arc-swap-0.4.3 \
		atty-0.2.13 \
		backtrace-0.2.3 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		bitflags-1.2.1 \
		c2-chacha-0.2.3 \
		cc-1.0.46 \
		cfg-if-0.1.10 \
		cpuprofiler-0.0.3 \
		dbghelp-sys-0.2.0 \
		env_logger-0.5.13 \
		error-chain-0.5.0 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		fuse-0.3.1 \
		getopts-0.2.21 \
		getrandom-0.1.13 \
		humantime-1.3.0 \
		itoa-0.4.4 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.4.0 \
		libc-0.2.65 \
		log-0.3.9 \
		log-0.4.8 \
		memchr-2.2.1 \
		nix-0.12.1 \
		pkg-config-0.3.16 \
		ppv-lite86-0.2.6 \
		proc-macro2-1.0.6 \
		quick-error-1.2.2 \
		quote-1.0.2 \
		rand-0.7.2 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.16 \
		ryu-1.0.2 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		serde_json-1.0.41 \
		signal-hook-0.1.10 \
		signal-hook-registry-1.1.1 \
		syn-1.0.5 \
		synstructure-0.12.1 \
		tempfile-3.1.0 \
		termcolor-1.0.5 \
		thread-scoped-1.0.2 \
		thread_local-0.3.6 \
		time-0.1.42 \
		unicode-width-0.1.6 \
		unicode-xid-0.2.0 \
		users-0.9.1 \
		void-1.0.2 \
		wasi-0.7.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2

PLIST_FILES=	bin/sandboxfs \
		man/man1/sandboxfs.1.gz

post-patch:
# libc crate defines ENOTSUP as an alias for EOPNOTSUPP.  nix crate
# does not re-export EOPNOTSUPP on FreeBSD but ENOTSUP is available.
	@${REINPLACE_CMD} 's,::EOPNOTSUPP,::ENOTSUP,' ${WRKSRC}/src/nodes/mod.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sandboxfs
	${INSTALL_MAN} ${WRKSRC}/man/sandboxfs.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

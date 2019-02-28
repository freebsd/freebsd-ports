# $FreeBSD$

PORTNAME=	sandboxfs
DISTVERSIONPREFIX=	sandboxfs-
DISTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Virtual file system for sandboxing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo fuse
USE_GITHUB=	yes
GH_ACCOUNT=	bazelbuild

CARGO_CRATES=	aho-corasick-0.6.9 \
		arc-swap-0.3.7 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.2.3 \
		backtrace-0.3.13 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		cc-1.0.29 \
		cfg-if-0.1.6 \
		cloudabi-0.0.3 \
		cpuprofiler-0.0.3 \
		dbghelp-sys-0.2.0 \
		env_logger-0.5.13 \
		error-chain-0.5.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		fuse-0.3.1 \
		getopts-0.2.18 \
		humantime-1.2.0 \
		itoa-0.4.3 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.2.0 \
		libc-0.2.49 \
		log-0.3.9 \
		log-0.4.6 \
		memchr-2.1.3 \
		nix-0.12.0 \
		pkg-config-0.3.14 \
		proc-macro2-0.4.27 \
		quick-error-1.2.2 \
		quote-0.6.11 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.2 \
		rand_os-0.1.2 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		regex-1.1.0 \
		regex-syntax-0.6.5 \
		remove_dir_all-0.5.1 \
		rustc-demangle-0.1.13 \
		rustc_version-0.2.3 \
		ryu-0.2.7 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.87 \
		serde_derive-1.0.87 \
		serde_json-1.0.38 \
		signal-hook-0.1.7 \
		syn-0.15.26 \
		synstructure-0.10.1 \
		tempfile-3.0.5 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		thread-scoped-1.0.2 \
		thread_local-0.3.6 \
		time-0.1.42 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

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

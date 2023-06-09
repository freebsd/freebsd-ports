PORTNAME=	nfs-exporter
DISTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	CRATESIO
MASTER_SITE_SUBDIR=	freebsd-${PORTNAME}/${DISTVERSION}
DISTNAME=	freebsd-${PORTNAME}-${DISTVERSIONFULL}
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Prometheus exporter for NFS statistics
WWW=		https://github.com/Axcient/freebsd-nfs-exporter

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

# https://github.com/tikv/rust-prometheus/issues/315
NOT_FOR_ARCHS=	powerpc
NOT_FOR_ARCHS_REASON_powerpc=needs 64-bit atomics

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_RC_SUBR=	nfs_exporter

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1302000
SUB_LIST=	USER=nobody
.else
SUB_LIST=	USER=root
.endif

CARGO_CRATES=	aho-corasick-0.7.20 \
		ascii-1.1.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bincode-1.3.3 \
		bindgen-0.60.1 \
		bindgen-0.64.0 \
		bitflags-1.3.2 \
		capsicum-0.2.0 \
		casper-sys-0.1.0 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chunked_transfer-1.4.1 \
		clang-sys-1.6.0 \
		clap-3.2.23 \
		clap_lex-0.2.4 \
		const-cstr-0.3.0 \
		ctor-0.1.26 \
		either-1.8.1 \
		env_logger-0.9.3 \
		fnv-1.0.7 \
		form_urlencoded-1.1.0 \
		glob-0.3.1 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		idna-0.3.0 \
		indexmap-1.9.2 \
		itoa-1.0.6 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.140 \
		libloading-0.7.4 \
		libnv-0.4.2 \
		libnv-sys-0.2.1 \
		lock_api-0.4.9 \
		log-0.4.17 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		once_cell-1.17.1 \
		os_str_bytes-6.4.1 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.7 \
		peeking_take_while-0.1.2 \
		percent-encoding-2.2.0 \
		proc-macro2-1.0.51 \
		prometheus-0.13.3 \
		prometheus_exporter-0.8.5 \
		quick-error-2.0.1 \
		quote-1.0.23 \
		redox_syscall-0.2.16 \
		regex-1.7.1 \
		regex-syntax-0.6.28 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		serde-1.0.154 \
		serde_derive-1.0.154 \
		shlex-1.1.0 \
		smallvec-1.10.0 \
		strsim-0.10.0 \
		syn-1.0.109 \
		termcolor-1.2.0 \
		textwrap-0.16.0 \
		thiserror-1.0.39 \
		thiserror-impl-1.0.39 \
		time-0.3.20 \
		time-core-0.1.0 \
		time-macros-0.2.8 \
		tiny_http-0.10.0 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unicode-bidi-0.3.11 \
		unicode-ident-1.0.8 \
		unicode-normalization-0.1.22 \
		url-2.3.1 \
		version_check-0.9.4 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.1 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.8 ${STAGEDIR}${MAN1PREFIX}/man/man8

.include <bsd.port.mk>

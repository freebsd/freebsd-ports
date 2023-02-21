PORTNAME=	nfs-exporter
DISTVERSION=	0.4.1
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

CARGO_CRATES=	aho-corasick-0.7.18 \
		ascii-1.0.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bincode-1.3.3 \
		bindgen-0.60.1 \
		bindgen-0.63.0 \
		bitflags-1.3.2 \
		capsicum-0.2.0 \
		casper-sys-0.1.0 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chunked_transfer-1.4.0 \
		clang-sys-1.3.1 \
		clap-3.2.23 \
		clap_lex-0.2.4 \
		const-cstr-0.3.0 \
		ctor-0.1.26 \
		either-1.6.1 \
		env_logger-0.9.0 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		glob-0.3.0 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		idna-0.2.3 \
		indexmap-1.9.1 \
		instant-0.1.12 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.139 \
		libloading-0.7.3 \
		libnv-0.4.1 \
		libnv-sys-0.2.0 \
		lock_api-0.4.6 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		minimal-lexical-0.2.1 \
		nom-7.1.1 \
		num_threads-0.1.4 \
		os_str_bytes-6.3.1 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		peeking_take_while-0.1.2 \
		percent-encoding-2.1.0 \
		proc-macro2-1.0.49 \
		prometheus-0.13.0 \
		prometheus_exporter-0.8.4 \
		quick-error-2.0.1 \
		quote-1.0.23 \
		redox_syscall-0.2.11 \
		regex-1.7.1 \
		regex-syntax-0.6.28 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		shlex-1.1.0 \
		smallvec-1.8.0 \
		strsim-0.10.0 \
		syn-1.0.107 \
		termcolor-1.1.3 \
		textwrap-0.16.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.3.7 \
		time-macros-0.2.3 \
		tiny_http-0.10.0 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.7 \
		unicode-ident-1.0.6 \
		unicode-normalization-0.1.19 \
		url-2.2.2 \
		version_check-0.9.4 \
		which-4.2.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.8 ${STAGEDIR}${MAN1PREFIX}/man/man8

.include <bsd.port.mk>

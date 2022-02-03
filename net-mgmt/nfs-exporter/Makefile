PORTNAME=	nfs-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	6
CATEGORIES=	net-mgmt

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Prometheus exporter for NFS statistics

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Axcient
GH_PROJECT=	freebsd-nfs-exporter
USE_RC_SUBR=	nfs_exporter

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		ascii-1.0.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.59.1 \
		bitflags-1.3.2 \
		bitvec-0.19.5 \
		cexpr-0.5.0 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		chunked_transfer-1.4.0 \
		clang-sys-1.2.0 \
		clap-2.33.3 \
		env_logger-0.7.1 \
		env_logger-0.8.4 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		funty-1.1.0 \
		glob-0.3.0 \
		hermit-abi-0.1.19 \
		humantime-1.3.0 \
		humantime-2.1.0 \
		idna-0.2.3 \
		instant-0.1.10 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.99 \
		libloading-0.7.0 \
		lock_api-0.4.4 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.0 \
		nom-6.1.2 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		peeking_take_while-0.1.2 \
		percent-encoding-2.1.0 \
		proc-macro2-1.0.28 \
		prometheus-0.12.0 \
		prometheus_exporter-0.8.2 \
		quick-error-1.2.3 \
		quote-1.0.9 \
		radium-0.5.3 \
		redox_syscall-0.2.10 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		shlex-1.0.0 \
		smallvec-1.6.1 \
		strsim-0.8.0 \
		syn-1.0.74 \
		tap-1.0.1 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		tiny_http-0.8.2 \
		tinyvec-1.3.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.6 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		which-3.1.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wyz-0.2.0

PLIST_FILES=	bin/nfs-exporter

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nfs-exporter

.include <bsd.port.mk>

PORTNAME=	continuwuity
DISTVERSION=	26.9.4
CATEGORIES=	net-im
MASTER_SITES=	https://forgejo.ellis.link/continuwuation/${PORTNAME}/archive/v${DISTVERSION}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Matrix homeserver written in Rust
WWW=		https://continuwuity.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream supports aarch64 and amd64 only

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	librocksdb.so:databases/rocksdb \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cargo pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
CARGO_VENDOR_DIR=	${WRKDIR}/cargo-crates

FJ_SITE=	https://forgejo.ellis.link/continuwuation
MASTER_SITES+=	${FJ_SITE}/rust-rocksdb-zaidoon1/archive/${ROCKSDB_RS_REV}${EXTRACT_SUFX}?dummy=/:rocksdbrs \
		${FJ_SITE}/jemallocator/archive/${JEMALLOCATOR_REV}${EXTRACT_SUFX}?dummy=/:jemalloc \
		${FJ_SITE}/rustyline-async/archive/${RUSTYLINE_REV}${EXTRACT_SUFX}?dummy=/:rustyline \
		${FJ_SITE}/event-listener/archive/${EVENT_LISTENER_REV}${EXTRACT_SUFX}?dummy=/:evlisten \
		${FJ_SITE}/async-channel/archive/${ASYNC_CHANNEL_REV}${EXTRACT_SUFX}?dummy=/:aschannel \
		${FJ_SITE}/core_affinity_rs/archive/${CORE_AFFINITY_REV}${EXTRACT_SUFX}?dummy=/:affinity \
		${FJ_SITE}/hyper-util/archive/${HYPER_UTIL_REV}${EXTRACT_SUFX}?dummy=/:hyperutil
DISTFILES+=	rust-rocksdb-zaidoon1-${ROCKSDB_RS_REV}${EXTRACT_SUFX}:rocksdbrs \
		jemallocator-${JEMALLOCATOR_REV}${EXTRACT_SUFX}:jemalloc \
		rustyline-async-${RUSTYLINE_REV}${EXTRACT_SUFX}:rustyline \
		event-listener-${EVENT_LISTENER_REV}${EXTRACT_SUFX}:evlisten \
		async-channel-${ASYNC_CHANNEL_REV}${EXTRACT_SUFX}:aschannel \
		core_affinity_rs-${CORE_AFFINITY_REV}${EXTRACT_SUFX}:affinity \
		hyper-util-${HYPER_UTIL_REV}${EXTRACT_SUFX}:hyperutil

ROCKSDB_RS_REV=	0a25ff92f7c09b55eec496b9c192c7d5136ab2b8
JEMALLOCATOR_REV=	df86ff89d4b1e223b9f7d2dd2fbb7f202da7f554
RUSTYLINE_REV=	b13aca2cc08d5f78303746cd192d9a03d73e768e
EVENT_LISTENER_REV=	b2c19bcaf5a0a69c38c034e417bda04a9b991529
ASYNC_CHANNEL_REV=	e990f0006b68dc9bace7a3c95fc90b5c4e44948d
CORE_AFFINITY_REV=	7c7a9dea35382743a63837cdd1d977efdb8f1b8a
HYPER_UTIL_REV=	09fcd3bf4656c81a8ad573bee410ab2b57f60b86

CARGO_INSTALL_PATH=	src/main
CARGO_ENV=	LIBCLANG_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib \
		ROCKSDB_USE_PKG_CONFIG=1
CARGO_FEATURES=	--no-default-features \
		bindgen-runtime \
		brotli_compression \
		direct_tls \
		element_hacks \
		gzip_compression \
		media_thumbnail \
		release_max_log_level \
		ring \
		url_preview \
		zstd_compression

USE_RC_SUBR=	${PORTNAME}

USERS=		continuwuity
GROUPS=		${USERS}

SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS} GROUP=${GROUPS}

PLIST_FILES=	bin/${PORTNAME} \
		"@sample(root,${GROUPS},0640) etc/${PORTNAME}/${PORTNAME}.toml.sample" \
		"@dir(${USERS},${GROUPS},0750) /var/db/${PORTNAME}"

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|^#database_path =.*|database_path = "/var/db/${PORTNAME}"|' \
		-e 's|^#log_colors = .*|log_colors = false|' \
		${WRKSRC}/conduwuit-example.toml

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/db/${PORTNAME}
	@${MV} ${STAGEDIR}${PREFIX}/bin/conduwuit ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/conduwuit-example.toml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.toml.sample

.include <bsd.port.mk>

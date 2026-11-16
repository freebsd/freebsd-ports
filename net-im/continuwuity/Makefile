PORTNAME=	continuwuity
DISTVERSION=	26.9.4
CATEGORIES=	net-im

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
USE_FORGEJO=	nodefault
FJ_HOST=	https://forgejo.ellis.link
FJ_TUPLE=	${FJ_HOST}:continuwuation:${PORTNAME}:v${DISTVERSION}:main \
		${FJ_HOST}:continuwuation:rust-rocksdb-zaidoon1:0a25ff92f7c09b55eec496b9c192c7d5136ab2b8:rocksdbrs \
		${FJ_HOST}:continuwuation:jemallocator:df86ff89d4b1e223b9f7d2dd2fbb7f202da7f554:jemalloc \
		${FJ_HOST}:continuwuation:rustyline-async:b13aca2cc08d5f78303746cd192d9a03d73e768e:rustyline \
		${FJ_HOST}:continuwuation:event-listener:b2c19bcaf5a0a69c38c034e417bda04a9b991529:evlisten \
		${FJ_HOST}:continuwuation:async-channel:e990f0006b68dc9bace7a3c95fc90b5c4e44948d:aschannel \
		${FJ_HOST}:continuwuation:core_affinity_rs:7c7a9dea35382743a63837cdd1d977efdb8f1b8a:affinity \
		${FJ_HOST}:continuwuation:hyper-util:09fcd3bf4656c81a8ad573bee410ab2b57f60b86:hyperutil

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
CARGO_VENDOR_DIR=	${WRKDIR}/cargo-crates

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

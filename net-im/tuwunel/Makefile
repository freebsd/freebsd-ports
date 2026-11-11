PORTNAME=	tuwunel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.4
CATEGORIES=	net-im

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	High performance Matrix homeserver written in Rust
WWW=		https://tuwunel.chat/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream supports aarch64 and amd64 only

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libzstd.so:archivers/zstd
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cargo cmake:indirect gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	matrix-construct
GH_TUPLE=	matrix-construct:rocksdb:${ROCKSDB_HASH}:rocksdb \
		matrix-construct:jemalloc:${JEMALLOC_HASH}:jemalloc

ROCKSDB_HASH=	d8a89161c6a53e79d61694289d2b78be36e6ca12
JEMALLOC_HASH=	ee054313a33bef077b946fe744adae423b1a1b4f

RUST_ROCKSDB_SRC=	${WRKDIR}/rust-rocksdb-${CARGO_CRATES:M*rust-rocksdb@git*:C/.*rev=([0-9a-f]+).*/\1/}
JEVMALLOC_SRC=	${WRKDIR}/jevmalloc-${CARGO_CRATES:M*jevmalloc-sys@git*:C/.*rev=([0-9a-f]+).*/\1/}

CARGO_INSTALL_PATH=	src/main
CARGO_ENV=	LIBCLANG_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib
CARGO_FEATURES=	--no-default-features \
		brotli_compression \
		element_hacks \
		gzip_compression \
		jemalloc \
		jemalloc_conf \
		media_thumbnail \
		release_max_log_level \
		url_preview \
		zstd_compression

USE_RC_SUBR=	${PORTNAME}

USERS=		tuwunel
GROUPS=		${USERS}

SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS}

PLIST_FILES=	bin/tuwunel \
		"@sample(root,${GROUPS},0640) etc/${PORTNAME}/${PORTNAME}.toml.sample" \
		"@dir(${USERS},${GROUPS},0750) /var/db/${PORTNAME}"

post-extract:
	@${RMDIR} ${RUST_ROCKSDB_SRC}/librocksdb-sys/rocksdb
	@${MV} ${WRKDIR}/rocksdb-${ROCKSDB_HASH} \
		${RUST_ROCKSDB_SRC}/librocksdb-sys/rocksdb
	@${RMDIR} ${JEVMALLOC_SRC}/jevmalloc-sys/jemalloc
	@${MV} ${WRKDIR}/jemalloc-${JEMALLOC_HASH} \
		${JEVMALLOC_SRC}/jevmalloc-sys/jemalloc

post-patch:
	@${REINPLACE_CMD} -e 's|^#database_path = .*|database_path = "/var/db/${PORTNAME}"|' \
		${WRKSRC}/${PORTNAME}-example.toml

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-example.toml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.toml.sample

.include <bsd.port.mk>

PORTNAME=	rustypaste
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
CATEGORIES=	www

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Minimal file upload/pastebin service
WWW=		https://github.com/orhun/rustypaste/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	orhun
USE_RC_SUBR=	${PORTNAME}

CARGO_FEATURES=	--no-default-features

SUB_LIST+=	USER="${USERS:[0]}"

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB+=	GROUP="${GROUPS:[0]}" \
		USER="${USERS:[0]}"

OPTIONS_DEFINE=		SHUTTLE
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	OPENSSL RUSTLS

OPENSSL_DESC=	Use distro OpenSSL (binary size is reduced ~20%)
RUSTLS_DESC=	Use modern TLS library in Rust
SHUTTLE_DESC=	Enable an entry point for deploying on Shuttle

OPENSSL_USES=	ssl

OPENSSL_VARS=		CARGO_FEATURES+=openssl
RUSTLS_VARS=		CARGO_FEATURES+=rustls
SHUTTLE_BUILD_DEPENDS=	protoc:devel/protobuf
SHUTTLE_VARS=		CARGO_FEATURES+=shuttle

UPLOAD_PATH=	/var/db/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/^upload_path[[:space:]]*=/s#=.*#= "${UPLOAD_PATH}"#' ${WRKSRC}/config.toml

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/${UPLOAD_PATH}
	${ECHO_CMD} 'CONFIG="${ETCDIR}/${PORTNAME}.toml"' > ${STAGEDIR}${ETCDIR}/${PORTNAME}.env.sample
	${CP} ${WRKSRC}/config.toml ${STAGEDIR}${ETCDIR}/${PORTNAME}.toml.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

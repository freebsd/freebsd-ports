PORTNAME=	libssh2
DISTVERSION=	1.11.1
PORTEPOCH=	3
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/ \
		https://www.libssh2.org/download/

PATCH_SITES=	https://github.com/libssh2/libssh2/commit/
PATCHFILES=	5d03b4f94ac6740e0085a6acda6fc417ca6ecc83.patch:-p1 \
		d4e43c7b69d10b6cfaaa53787addfd4beac7a3ce.patch:-p1

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol
WWW=		https://www.libssh2.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing cpe pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_TESTING \
		RUN_DOCKER_TESTS \
		RUN_SSHD_TESTS

CMAKE_ON=	ENABLE_ZLIB_COMPRESSION

OPTIONS_DEFINE=		STATIC TRACE
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GCRYPT OPENSSL
OPTIONS_DEFAULT=	OPENSSL ZLIB
OPTIONS_SUB=		yes

TRACE_DESC=		Enable debug packet traces

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CMAKE_ON=	-DCRYPTO_BACKEND=Libgcrypt

OPENSSL_USES=		ssl
OPENSSL_CMAKE_ON=	-DCRYPTO_BACKEND=OpenSSL

STATIC_CMAKE_BOOL=	BUILD_STATIC_LIBS

TRACE_CMAKE_BOOL=	ENABLE_DEBUG_LOGGING

.include <bsd.port.mk>

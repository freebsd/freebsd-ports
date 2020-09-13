# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libssh
PORTVERSION=	0.9.5
CATEGORIES=	security devel
MASTER_SITES=	https://www.libssh.org/files/${PORTVERSION:R}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe tar:xz

CMAKE_OFF=	WITH_EXAMPLES
CMAKE_ON=	BUILD_STATIC_LIB
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GSSAPI ZLIB
OPTIONS_RADIO=	CRYPTO
OPTIONS_RADIO_CRYPTO=	GCRYPT OPENSSL
OPTIONS_DEFAULT=GSSAPI OPENSSL ZLIB

GCRYPT_CMAKE_BOOL=	WITH_GCRYPT
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GSSAPI_CMAKE_BOOL=	WITH_GSSAPI
OPENSSL_USES=		ssl
ZLIB_CMAKE_BOOL=	WITH_ZLIB

post-patch:
	@${RM} ${PATCH_WRKSRC}/cmake/Modules/UseDoxygen.cmake

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/src/libssh.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>

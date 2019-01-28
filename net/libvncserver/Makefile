# Created by: ijliao
# $FreeBSD$

PORTNAME=	libvncserver
PORTVERSION=	0.9.12
DISTVERSIONPREFIX=	LibVNCServer-
CATEGORIES=	net devel

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Provide an easy API to a custom vnc server

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		liblzo2.so:archivers/lzo2

USES=		cmake jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LibVNC

OPTIONS_DEFINE=		GCRYPT IPV6
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL
GCRYPT_DESC=		libgcrypt support

GNUTLS_IMPLIES=		GCRYPT
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CMAKE_BOOL=	WITH_GNUTLS

OPENSSL_CMAKE_BOOL=	WITH_OPENSSL
OPENSSL_USES=		ssl

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_CMAKE_BOOL=	WITH_GCRYPT

IPV6_CMAKE_BOOL=	WITH_IPv6

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${STAGEDIR}${PREFIX}/include/rfb

.include <bsd.port.mk>

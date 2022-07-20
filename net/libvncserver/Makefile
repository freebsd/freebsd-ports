PORTNAME=	libvncserver
PORTVERSION=	0.9.13
DISTVERSIONPREFIX=	LibVNCServer-
PORTREVISION=	1
CATEGORIES=	net devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	132c1389390c.patch:-p1 # https://github.com/LibVNC/libvncserver/pull/453
PATCHFILES+=	0becaf749e83.patch:-p1 # https://github.com/LibVNC/libvncserver/pull/453

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Provide an easy API to a custom vnc server

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		liblzo2.so:archivers/lzo2

USES=		cmake cpe jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes

CPE_VENDOR=	libvncserver_project

CMAKE_ON=	WITH_24BPP WITH_JPEG WITH_LZO WITH_PNG \
		WITH_THREADS WITH_TIGHTVNC_FILETRANSFER \
		WITH_WEBSOCKETS WITH_ZLIB
CMAKE_OFF=	WITH_FFMPEG WITH_SDL WITH_SYSTEMD

USE_GITHUB=	yes
GH_ACCOUNT=	LibVNC

OPTIONS_DEFINE=		GCRYPT IPV6 SASL
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	GCRYPT OPENSSL
GCRYPT_DESC=		libgcrypt support
SASL_DESC=		SASL support

GCRYPT_CMAKE_BOOL=	WITH_GCRYPT
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error

IPV6_CMAKE_BOOL=	WITH_IPv6

SASL_CMAKE_BOOL=	WITH_SASL
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

GNUTLS_IMPLIES=		GCRYPT
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CMAKE_BOOL=	WITH_GNUTLS

OPENSSL_CMAKE_BOOL=	WITH_OPENSSL
OPENSSL_USES=		ssl

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${STAGEDIR}${PREFIX}/include/rfb

.include <bsd.port.mk>

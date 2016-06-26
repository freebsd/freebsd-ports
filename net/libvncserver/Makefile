# Created by: ijliao
# $FreeBSD$

PORTNAME=	libvncserver
PORTVERSION=	0.9.10
DISTVERSIONPREFIX=	LibVNCServer-
PORTREVISION=	1
CATEGORIES=	net devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an easy API to a custom vnc server

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	LibVNC

USES=		autoreconf jpeg libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		GCRYPT IPV6 VAAPI
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL
GCRYPT_DESC=		libgcrypt support

GNUTLS_IMPLIES=		GCRYPT
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

OPENSSL_CONFIGURE_WITH=	crypto ssl
OPENSSL_USE=		OPENSSL=yes

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_CONFIGURE_WITH=	gcrypt

IPV6_CONFIGURE_WITH=	ipv6

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CONFIGURE_WITH=	libva

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${STAGEDIR}${PREFIX}/include/rfb

.include <bsd.port.mk>

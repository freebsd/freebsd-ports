# Created by: ijliao
# $FreeBSD$

PORTNAME=	libvncserver
PORTVERSION=	0.9.9
PORTREVISION=	5
CATEGORIES=	net devel
MASTER_SITES=	SF
DISTNAME=	LibVNCServer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an easy API to write one's own vnc server

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

USES=	pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-x

OPTIONS_DEFINE=	GNUTLS OPENSSL GCRYPT IPV6
OPTIONS_DEFAULT=	OPENSSL
GCRYPT_DESC=	libgcrypt support

GNUTLS_LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls
GNUTLS_CONFIGURE_OFF=	--without-gnutls

OPENSSL_CONFIGURE_ON=	--with-ssl
OPENSSL_CONFIGURE_OFF=	--without-crypto --without-ssl

GCRYPT_LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_ON=	--with-gcrypt
GCRYPT_CONFIGURE_OFF=	--without-gcrypt

IPV6_CONFIGURE_ON=	--with-ipv6
IPV6_CONFIGURE_OFF=	--without-ipv6

OPENSSL_USE=	OPENSSL=yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|x11vnc||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${STAGEDIR}${PREFIX}/include/rfb

.include <bsd.port.mk>

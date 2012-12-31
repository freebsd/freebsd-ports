# Created by: ijliao
# $FreeBSD$

PORTNAME=	libvncserver
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	SF
DISTNAME=	LibVNCServer-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Provide an easy API to write one's own vnc server

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-x

OPTIONS_DEFINE=	GNUTLS OPENSSL GCRYPT
OPTIONS_DEFAULT=	OPENSSL
GNUTLS_DESC=	Enable GnuTLS support
OPENSSL_DESC=	Enable OpenSSL support
GCRYPT_DESC=	Enable libgcrypt support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS=		--with-ssl
.else
CONFIGURE_ARGS+=	--without-crypto --without-ssl
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--with-gcrypt
.else
CONFIGURE_ARGS+=	--without-gcrypt
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|x11vnc||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${PREFIX}/include/rfb

.include <bsd.port.mk>

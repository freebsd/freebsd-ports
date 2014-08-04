# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.4.3
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	security devel
MASTER_SITES=	http://www.libssh2.org/download/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol

LICENSE=	BSD3CLAUSE

USE_OPENSSL=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GCRYPT TRACE ZLIB
OPTIONS_DEFAULT=	ZLIB

TRACE_DESC=	Enable debug packet traces

TRACE_CONFIGURE_ENABLE=	debug
GCRYPT_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_ON=	--with-libgcrypt -with-libgcrypt-prefix=${LOCALBASE} --without-openssl
GCRYPT_CFLAGS=		-I${LOCALBASE}/include
GCRYPT_LDFLAGS=		-L${LOCALBASE}/lib
ZLIB_CONFIGURE_WITH=	libz

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITH_OPENSSL_BASE)
	@${REINPLACE_CMD} -e '/LIBSREQUIRED=/ s|libssl,libcrypto||' \
		${WRKSRC}/configure.ac ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

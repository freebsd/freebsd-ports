# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.8.0
PORTEPOCH=	3
CATEGORIES=	security devel
MASTER_SITES=	http://www.libssh2.org/download/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GCRYPT TRACE ZLIB
OPTIONS_DEFAULT=	ZLIB

TRACE_DESC=	Enable debug packet traces

TRACE_CONFIGURE_ENABLE=	debug
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CONFIGURE_ON=	--with-libgcrypt
GCRYPT_CONFIGURE_OFF=	--with-openssl
GCRYPT_CPPFLAGS=	-I${LOCALBASE}/include
GCRYPT_LIBS=		-L${LOCALBASE}/lib
GCRYPT_USE_OFF=	openssl=yes
ZLIB_CONFIGURE_WITH=	libz

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MGCRYPT) && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

post-patch:
	@${REINPLACE_CMD} -e '/Libs:/s/@LIBS@//' \
		${WRKSRC}/libssh2.pc.in
.if ! ${PORT_OPTIONS:MGCRYPT}
.  if ${SSL_DEFAULT} == base
	@${REINPLACE_CMD} -e 's/LIBSREQUIRED=libssl,libcrypto/LIBS="$$LIBS -lssl -lcrypto"/' \
		${WRKSRC}/configure
.  endif
.endif

.include <bsd.port.post.mk>

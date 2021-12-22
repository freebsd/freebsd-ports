# Created by: Alexander Leidinger <netchild@FreeBSD.org>

PORTNAME=	libssh2
PORTVERSION=	1.10.0
PORTEPOCH=	3
CATEGORIES=	security devel
MASTER_SITES=	https://www.libssh2.org/download/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 cpe libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	GCRYPT TRACE ZLIB
OPTIONS_DEFAULT=	ZLIB

TRACE_DESC=	Enable debug packet traces

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_USES_OFF=	ssl
GCRYPT_CONFIGURE_ON=	--with-crypto=libgcrypt
GCRYPT_CONFIGURE_OFF=	--with-crypto=openssl
GCRYPT_CPPFLAGS=	-I${LOCALBASE}/include
GCRYPT_LIBS=		-L${LOCALBASE}/lib
TRACE_CONFIGURE_ENABLE=	debug
ZLIB_CONFIGURE_WITH=	libz

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/Libs:/s/@LIBS@//' \
		${WRKSRC}/libssh2.pc.in
.if ! ${PORT_OPTIONS:MGCRYPT}
.  if ${SSL_DEFAULT} == base
	@${REINPLACE_CMD} -e 's/LIBSREQUIRED="$$LIBSREQUIRED$${LIBSREQUIRED:+ }libssl libcrypto"/LIBS="$$LIBS -lssl -lcrypto"/' \
		${WRKSRC}/configure
.  endif
.endif

.include <bsd.port.post.mk>

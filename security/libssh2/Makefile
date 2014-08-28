# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.4.3
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	security devel
MASTER_SITES=	http://www.libssh2.org/download/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GCRYPT TRACE ZLIB
OPTIONS_DEFAULT=	ZLIB

TRACE_DESC=	Enable debug packet traces

TRACE_CONFIGURE_ENABLE=	debug
GCRYPT_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_ON=	--with-libgcrypt --without-openssl
GCRYPT_CONFIGURE_OFF=	--without-libgcrypt --with-openssl
GCRYPT_CPPFLAGS=	-I${LOCALBASE}/include
GCRYPT_LIBS=		-L${LOCALBASE}/lib
ZLIB_CONFIGURE_WITH=	libz

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MGCRYPT}
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/Libs:/s/@LDFLAGS@//' -e '/Libs:/s/@LIBS@//' \
		${WRKSRC}/libssh2.pc.in
.if defined(WITH_OPENSSL_BASE)
	@${REINPLACE_CMD} -e 's/LIBSREQUIRED=libssl,libcrypto/LIBS="$$LIBS -lssl -lcrypto"/' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>

# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.7.0
PORTEPOCH=	2
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

post-build:
	@${REINPLACE_CMD} -E -e '/Requires.private:/{s/[[:<:]]zlib[[:>:]]//;s/,,/,/;s/ ,/ /;s/,$$//;}' \
		${WRKSRC}/libssh2.pc

# allow maintainer to generate MAN3 manpages list (make extract is required before)
x-generate-man3: extract
	@(cd ${WRKSRC}/docs && ${LS} -1F *.3 | ${SORT} | ${CUT} -d '/' -f4 \
		| ${GREP} -v template)

.include <bsd.port.post.mk>

# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.4.3
PORTREVISION=	1
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

.include <bsd.port.options.mk>

TRACE_DESC=	Enable debug packet traces

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTRACE}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--with-libgcrypt -with-libgcrypt-prefix=${LOCALBASE} --without-openssl
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MZLIB}
CONFIGURE_ARGS+=	--with-libz
.else
CONFIGURE_ARGS+=	--without-libz
.endif

# allow maintainer to generate MAN3 manpages list (make extract is required before)
x-generate-man3: extract
	@(cd ${WRKSRC}/docs && ${LS} -1F *.3 | ${SORT} | ${CUT} -d '/' -f4 \
		| ${GREP} -v template)

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

# Created by: delphij@FreeBSD.org
# $FreeBSD$

PORTNAME=	libvmime
PORTVERSION=	0.9.1
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	SF/vmime/vmime/0.9

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	An all-in-one Internet mail library

LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	libgsasl.so:${PORTSDIR}/security/gsasl

USES=		iconv gmake pkgconfig tar:bzip2 libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -D_GLIBCXX__PTHREADS
CXXFLAGS+=	${CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib

.ifndef	DEBUG
CONFIGURE_ARGS+=--disable-debug
.endif

CONFIGURE_ENV+=	EXTRA_CFLAGS="${CFLAGS}" EXTRA_CXXFLAGS="${CXXFLAGS}" \
		LIBGNUTLS_CONFIG="${LOCALBASE}/bin/pkg-config" libgnutls_config_args="gnutls"

DOCSDIR=	${PREFIX}/share/doc/vmime

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>

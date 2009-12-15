# New ports collection makefile for:    libvmime
# Date created:				September 17, 2005
# Whom:					delphij@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libvmime
PORTVERSION=	0.9.0
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	SF/vmime/vmime/0.9

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	An all-in-one Internet mail library

LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	gsasl.14:${PORTSDIR}/security/gsasl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include -D_GLIBCXX__PTHREADS
CXXFLAGS+=	${CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib

.ifndef	DEBUG
CONFIGURE_ARGS+=--disable-debug
.endif

CONFIGURE_ENV+=	EXTRA_CFLAGS="${CFLAGS}" EXTRA_CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBGNUTLS_CONFIG="${LOCALBASE}/bin/pkg-config" libgnutls_config_args="gnutls"

DOCSDIR=	${PREFIX}/share/doc/vmime

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	b2sum
PORTVERSION=	20190724
CATEGORIES=	sysutils security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast secure hashing

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/../COPYING

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LDFLAGS}"
MAKEFILE=	makefile
USE_CSTD=	c99
WRKSRC_SUBDIR=	b2sum

PLIST_FILES=	bin/b2sum

USE_GITHUB=	yes
GH_ACCOUNT=	BLAKE2
GH_PROJECT=	BLAKE2
GH_TAGNAME=	997fa5b

OPTIONS_DEFINE=	OPENMP OPTIMIZED_CFLAGS SSE
OPTIONS_DEFAULT_amd64=	SSE
SSE_DESC=	Use SSE2, SSSE3, SSE4.1, AVX or XOP instructions

OPENMP_USES+=	compiler:openmp
OPENMP_CFLAGS+=	-fopenmp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3
.if !${CFLAGS:M-march=*}
CFLAGS+=	-march=native
.endif
.endif

.if (${PORT_OPTIONS:MSSE} && (${ARCH} == "i386" || ${ARCH} == "amd64"))
CFLAGS+=	-I../sse -flax-vector-conversions
.else
CFLAGS+=	-I../ref
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/b2sum ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

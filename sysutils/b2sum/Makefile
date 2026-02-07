PORTNAME=	b2sum
PORTVERSION=	20190724
PORTREVISION=	2
CATEGORIES=	sysutils security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast secure hashing
WWW=		https://blake2.net/ \
		https://github.com/BLAKE2/BLAKE2

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/../COPYING

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LDFLAGS}"
MAKEFILE=	makefile
USE_CSTD=	c99
WRKSRC_SUBDIR=	b2sum

PLIST_FILES=	bin/b2sum \
		share/man/man1/b2sum.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	BLAKE2
GH_PROJECT=	BLAKE2

OPTIONS_DEFINE=	OPENMP OPTIMIZED_CFLAGS SSE
.if exists(/usr/include/omp.h)
OPTIONS_DEFAULT+=	OPENMP
.endif
OPTIONS_DEFAULT_amd64=	SSE
SSE_DESC=	Use SSE2, SSSE3, SSE4.1, AVX or XOP instructions

OPENMP_CFLAGS=	-fopenmp

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
	${INSTALL_PROGRAM} ${WRKSRC}/b2sum ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/b2sum.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>

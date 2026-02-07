PORTNAME=	blis
PORTVERSION=	2.0
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Software framework for high-performance BLAS-like libraries
WWW=		https://github.com/flame/blis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler fortran gmake perl5 python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	flame

USE_PERL5=	build
SHEBANG_FILES=	build/flatten-headers.py
BIN_ALIAS=	gfortran=${FC}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PARA CBLAS
PARA_DESC=	use pthread parallelization
CBLAS_DESC=	build the CBLAS compatibility layer
OPTIONS_DEFAULT=	PARA
OPTIONS_SUB=		yes

CFLAGS_riscv64=	-mno-relax
HAS_CONFIGURE=	yes

TEST_TARGET=	test

.include <bsd.port.options.mk>

# enable BLAS and static/shared libs by default
CONFIGURE_ARGS+=	--enable-blas \
			--prefix=${PREFIX} \
			--enable-shared \
			--enable-static

.if ${PORT_OPTIONS:MPARA}
CONFIGURE_ARGS+=	-t pthreads
.endif

.if ${PORT_OPTIONS:MCBLAS}
CONFIGURE_ARGS+=	--enable-cblas
CONFLICTS_INSTALL=	openblas-*
.endif

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	x86_64
PLIST_SUB+=	ARCH="x86_64"
.elif ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	power9
PLIST_SUB+=	ARCH="power9"
USE_GCC=	yes
.else
CONFIGURE_ARGS+=	generic
PLIST_SUB+=	ARCH="generic"
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 190
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-config_knl_make__defs.mk
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libblis.so.4.0.0

.include <bsd.port.post.mk>

# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blis
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Software framework for high-performance BLAS-like libraries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

BROKEN_powerpc64=	fails to configure: common.mk:118: Unable to determine compiler vendor

OPTIONS_DEFINE=	PARA CBLAS
PARA_DESC=	use pthread parallelization
CBLAS_DESC=	build the CBLAS compatibility layer
OPTIONS_RADIO=		ARCHITECTURE
OPTIONS_RADIO_ARCHITECTURE=	REFERENCE BULLDOZER PILEDRIVER CARRIZO DUNNINGTON SANDYBRIDGE HASWELL
REFERENCE_DESC=	reference kernels (slow)
BULLDOZER_DESC=	optimized kernels for AMD Bulldozer architecture
PILEDRIVER_DESC=	optimized kernels for AMD Piledriver architecture
CARRIZO_DESC=	optimized kernels for AMD Carrizo architecture
DUNNINGTON_DESC=	optimized kernels for Intel Dunnington architecture
SANDYBRIDGE_DESC=	optimized kernels for Intel Sandybridge architecture
HASWELL_DESC=	optimized kernels for Intel Haswell architecture
OPTIONS_DEFAULT=	PARA CBLAS REFERENCE
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flame
GH_TAGNAME=	6e04f9d

USE_LDCONFIG=	yes
USES=		gmake

HAS_CONFIGURE=	yes

.include <bsd.port.options.mk>

# enable BLAS and static/shared libs by default
CONFIGURE_ARGS+=	--enable-blas \
			--prefix=${PREFIX} \
			--enable-shared \
			--enable-static
#--prefix=PREFIX

.if ${PORT_OPTIONS:MPARA}
CONFIGURE_ARGS+=	-t pthreads
.endif

.if ${PORT_OPTIONS:MCBLAS}
CONFIGURE_ARGS+=	--enable-cblas
.endif

ARCH=	reference
.if ${PORT_OPTIONS:MREFERENCE}
ARCH=	reference
.elif ${PORT_OPTIONS:MBULLDOZER}
ARCH=	bulldozer
.elif ${PORT_OPTIONS:MPILEDRIVER}
ARCH=	piledriver
.elif ${PORT_OPTIONS:MCARRIZO}
ARCH=	carrizo
.elif ${PORT_OPTIONS:MDUNNINGTON}
ARCH=	dunnington
.elif ${PORT_OPTIONS:MSANDYBRIDGE}
ARCH=	sandybridge
.elif ${PORT_OPTIONS:MHASWELL}
ARCH=	haswell
.endif
CONFIGURE_ARGS+=	${ARCH}

post-install:
	${MV} ${STAGEDIR}/${PREFIX}/lib/libblis-${PORTVERSION}-${ARCH}.a ${STAGEDIR}/${PREFIX}/lib/libblis.a
	${MV} ${STAGEDIR}/${PREFIX}/lib/libblis-${PORTVERSION}-${ARCH}.so ${STAGEDIR}/${PREFIX}/lib/libblis.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libblis.so

.include <bsd.port.mk>

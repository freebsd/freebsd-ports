# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blis
LIBVERSION=	0.3.2
PORTVERSION=	${LIBVERSION}g20180501
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Software framework for high-performance BLAS-like libraries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		llvm50>=0:devel/llvm50

BROKEN_powerpc64=	fails to configure: common.mk:118: Unable to determine compiler vendor

OPTIONS_DEFINE=	PARA CBLAS
PARA_DESC=	use pthread parallelization
CBLAS_DESC=	build the CBLAS compatibility layer
OPTIONS_DEFAULT=	PARA CBLAS
OPTIONS_SUB=		yes

USE_GITHUB=	yes
GH_ACCOUNT=	flame
GH_TAGNAME=	8adb2f9

USES=		gmake
USE_LDCONFIG=	yes

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

.if ${ARCH} == amd64
LIBNAME=	x86_64
CONFIGURE_ARGS+=	x86_64
PLIST_SUB+=	X8664=""
.else
LIBNAME=	generic
CONFIGURE_ARGS+=	generic
PLIST_SUB+=	X8664="@comment "
.endif

CC=	${LOCALBASE}/bin/clang50
CXX=	${LOCALBASE}/bin/clang++50

post-install:
	${MV} ${STAGEDIR}/${PREFIX}/lib/libblis-${LIBVERSION}-${LIBNAME}.a ${STAGEDIR}/${PREFIX}/lib/libblis.a
	${MV} ${STAGEDIR}/${PREFIX}/lib/libblis-${LIBVERSION}-${LIBNAME}.so ${STAGEDIR}/${PREFIX}/lib/libblis.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libblis.so

.include <bsd.port.mk>

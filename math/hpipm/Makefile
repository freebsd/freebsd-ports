PORTNAME=	hpipm
DISTVERSION=	0.1.3-225 # new release is promised here: https://github.com/giaf/hpipm/issues/170
DISTVERSIONSUFFIX=	-g79008aa
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance interior-point-method QP solvers
WWW=		https://github.com/giaf/hpipm

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libblasfeo.so:math/blasfeo

USES=		cmake:testing localbase
USE_GITHUB=	yes
GH_ACCOUNT=	giaf

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	HPIPM_TESTING
CMAKE_ARGS=	-DHPIPM_BLASFEO_LIB=Shared \
		-DTARGET=GENERIC
CMAKE_TESTING_ON=	HPIPM_TESTING
CMAKE_TESTING_TARGET=

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DAVX:BOOL=OFF
.endif

post-test: # run tests
.for t in d_cond d_dense_qp d_ocp_qp d_part_cond d_tree_ocp_qp
	@${ECHO} "==> Running test ${t}"
	@cd ${TEST_WRKSRC} && test_problems/${t}
.endfor

# testcase test_problems/d_dense_qp crashes, see https://github.com/giaf/hpipm/issues/175

.include <bsd.port.post.mk>

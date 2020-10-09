# $FreeBSD$

PORTNAME=	axom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Infrastructure for development of multi-physics applications and tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libconduit.so:science/conduit
RUN_DEPENDS=	sparsehash>0:devel/sparsehash

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	LLNL:blt:095becb5af6af5c2a2290d2fbcb5246cc01e7345:LLNL_blt/cmake/blt \
		LLNL:axom_data:c434d0723843b4013a922771ef2cf3cc73fb32d8:LLNL_axom_data/../data

CMAKE_OFF=	AXOM_ENABLE_DOCS AXOM_ENABLE_EXAMPLES AXOM_ENABLE_TESTS FREEBSD_ENABLE_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DCONDUIT_DIR=${LOCALBASE}

LDFLAGS+=	-lexecinfo

WRKSRC_SUBDIR=	src

post-install: # installs headers of a third party library sparsehash: https://github.com/LLNL/axom/issues/365
	@${RM} -r ${STAGEDIR}${PREFIX}/include/sparsehash

.include <bsd.port.mk>

PORTNAME=	lean
DISTVERSIONPREFIX=	v
DISTVERSION=	3.48.0
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	5eecaa0b9c860858372a22ab242566671907c913.patch:-p2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover-community

WRKSRC_SUBDIR=	src

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

OPTIONS_DEFINE=		TCMALLOC THREADS
OPTIONS_DEFAULT=	TCMALLOC THREADS

TCMALLOC_DESC=		Use tcmalloc from google-perftools as memory allocator
TCMALLOC_CMAKE_BOOL=	TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

THREADS_CMAKE_BOOL=	MULTI_THREAD

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>

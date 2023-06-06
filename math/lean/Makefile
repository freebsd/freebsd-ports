PORTNAME=	lean
DISTVERSIONPREFIX=	v
DISTVERSION=	3.51.1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	5eecaa0b9c860858372a22ab242566671907c913.patch:-p2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover
WWW=		https://leanprover-community.github.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_aarch64=	c++ crashes during link on arm64 on math/lean, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=266777

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover-community

WRKSRC_SUBDIR=	src

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

OPTIONS_DEFINE=		TCMALLOC THREADS
OPTIONS_DEFAULT=	TCMALLOC THREADS
OPTIONS_EXCLUDE_powerpc=	TCMALLOC

TCMALLOC_CMAKE_BOOL=	TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

THREADS_CMAKE_BOOL=	MULTI_THREAD

post-build: # workaround for https://github.com/leanprover-community/lean/issues/765
	@cd ${WRKSRC}/../library && ${BUILD_WRKSRC}/shell/lean --make

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>

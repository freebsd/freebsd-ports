PORTNAME=	metis
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.3.10
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://coin-or-tools.github.io/ThirdParty-Metis/:metis
PKGNAMEPREFIX=	coin-or-
DISTFILES=	metis-${METIS_VERSION}.tar.gz:metis

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	COIN-OR autotools harness to build Metis
WWW=		https://github.com/coin-or-tools/ThirdParty-Mumps

LICENSE=	EPL

LIB_DEPENDS=	libblas.so:math/blas

USES=		fortran gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or-tools
GH_PROJECT=	ThirdParty-Metis

GNU_CONFIGURE=	yes

# Adaption of the upstream fix for Clang/Flang
# https://github.com/coin-or-tools/ThirdParty-Metis/commit/5ace49007591f11b64f70183102549d3a9721d4b
CFLAGS=		-Wno-implicit-function-declaration
INSTALL_TARGET=	install-strip

METIS_VERSION=	4.0.3 # from the script get.Metis

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (scalar and rank-1)
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

post-extract: # link MUMPS into the location in the tree
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/metis-${METIS_VERSION} metis-4.0

pre-build: # patching from get.Metis
	@cd ${WRKDIR} && \
		${PATCH} -p0 < ${WRKSRC}/metis.patch

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	csdp
DISTVERSIONPREFIX=	releases/
DISTVERSION=	6.2.0
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for semidefinite programming problems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Csdp
USE_LDCONFIG=	yes

MAKE_ARGS=	FREEBSD_CFLAGS="${CFLAGS}" FREEBSD_LIBS="${LIBS} -L${LOCALBASE}/lib"

BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/complement \
		bin/csdp \
		bin/graphtoprob \
		bin/rand_graph \
		bin/theta

.include <bsd.port.pre.mk>

# XXX Drop after FreeBSD 12.0 EOL
.if !exists(/usr/include/omp.h)
LIB_DEPENDS+=	libomp.so:devel/openmp
.endif

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.post.mk>

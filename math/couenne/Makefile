PORTNAME=	couenne
DISTVERSIONPREFIX=	releases/
DISTVERSION=	0.5.8
PORTREVISION=	6
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convex Over and Under Envelopes for NonliNear Estimation

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Couenne/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libnauty.a:math/nauty
LIB_DEPENDS=	libbonmin.so:math/bonmin \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libCoinUtils.so:math/coinutils \
		libipopt.so:math/ipopt \
		libopenblas.so:math/openblas

USES=		blaslapack:netlib fortran gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Couenne

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-nauty-incdir=${LOCALBASE}/include/nauty --with-nauty-lib=${LOCALBASE}/lib/libnauty.a

INSTALL_TARGET=	install-strip

SUB_FILES=	${PORTNAME}.msc
SUB_LIST=	PORTVERSION=${PORTVERSION}

post-install:
	# install MiniZinc configuration file
	${MKDIR} ${STAGEDIR}${PREFIX}/share/minizinc/solvers
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.msc ${STAGEDIR}${PREFIX}/share/minizinc/solvers

.include <bsd.port.mk>

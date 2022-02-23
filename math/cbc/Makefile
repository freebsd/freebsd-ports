PORTNAME=	cbc
DISTVERSIONPREFIX=	releases/
DISTVERSION=	2.10.5
PORTREVISION=	5
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coin-or Branch and Cut: mixed integer programming solver

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Cbc/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/ipopt \
		libCoinUtils.so:math/coinutils \
		liblapack.so:math/lapack \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi

USES=		compiler:c++11-lang fortran gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Cbc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-nauty-lib="-L${LOCALBASE}/lib -lnauty" --with-nauty-incdir=${LOCALBASE}/include/nauty

CONFLICTS_INSTALL=	libcouchbase # bin/cbc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>

PORTNAME=	disco
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.0.0-33
PORTREVISION=	2
DISTVERSIONSUFFIX=	-g68720be
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Discrete Conic Optimization Solver

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libnauty.a:math/nauty
LIB_DEPENDS=	libAlps.so:math/alps \
		libBcps.so:math/bcps \
		libblas.so:math/blas \
		libbonmin.so:math/bonmin \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libCglConic.so:math/cgl-conic \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libCoinUtils.so:math/coinutils \
		libipopt.so:math/ipopt \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libOsiConic.so:math/osi-conic \
		libOsiIpopt.so:math/osiipopt

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	DisCO

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	disco mono mono[0-9]*

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

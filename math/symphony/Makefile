PORTNAME=	symphony
DISTVERSIONPREFIX=	releases/
DISTVERSION=	5.6.19
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver and development framework for mixed-integer linear programs

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/SYMPHONY/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libClp.so:math/clp

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	${PORTNAME:tu}

INSTALL_TARGET=	install-strip
TEST_TARGET=	test

.include <bsd.port.mk>

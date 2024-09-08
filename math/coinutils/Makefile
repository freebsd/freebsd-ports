PORTNAME=	CoinUtils
DISTVERSIONPREFIX=	releases/
DISTVERSION=	2.11.12
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities for COIN-OR project
WWW=		https://github.com/coin-or/CoinUtils

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/CoinUtils/LICENSE

COIN_DEPENDS=	coin-or-Data-Sample>0:math/coin-or-data-sample \
		coin-or-Data-Netlib>0:math/coin-or-data-netlib
BUILD_DEPENDS=	${COIN_DEPENDS}
LIB_DEPENDS=	libopenblas.so:math/openblas
RUN_DEPENDS=	${COIN_DEPENDS}

USES=		fortran gmake libtool localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas-lib="-lopenblas" --with-lapack-lib="-lopenblas" \
		--with-sample-datadir="${LOCALBASE}/share/coin/Data/Sample" \
		--with-netlib-datadir="${LOCALBASE}/share/coin/Data/Netlib"
		# doesn't link with the optional dependency glpk: https://github.com/coin-or/CoinUtils/issues/7
USE_LDCONFIG=	yes

CPPFLAGS+=	-Dregister=

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or

INSTALL_TARGET=	install-strip
TEST_TARGET=	test

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/coin

.include <bsd.port.mk>

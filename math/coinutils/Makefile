# $FreeBSD$

PORTNAME=	CoinUtils
DISTVERSION=	2.11.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME}/
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities for COIN-OR project

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/CoinUtils/LICENSE

BUILD_DEPENDS=	coin-or-Data-Sample>0:math/coin-or-data-sample \
		coin-or-Data-Netlib>0:math/coin-or-data-netlib
LIB_DEPENDS=	libopenblas.so:math/openblas
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fortran gmake libtool localbase:ldflags pkgconfig zip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas-lib="-lopenblas" --with-lapack-lib="-lopenblas" \
		--with-sample-datadir="${LOCALBASE}/share/coin/Data/Sample" \
		--with-netlib-datadir="${LOCALBASE}/share/coin/Data/Netlib"
		# doesn't link with the optional dependency glpk: https://github.com/coin-or/CoinUtils/issues/7
USE_LDCONFIG=	yes

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/coin

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	Osi
DISTVERSION=	0.107.9
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME}/
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	COIN-OR Open Solver Interface, an API for calling solver libraries

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Osi/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libCoinUtils.so:math/coinutils \
		libopenblas.so:math/openblas
RUN_DEPENDS=	coin-or-Data-Sample>0:math/coin-or-data-sample \
		coin-or-Data-Netlib>0:math/coin-or-data-netlib

USES=		fortran gmake libtool localbase:ldflags pkgconfig tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas-lib="-lopenblas" --with-lapack-lib="-lopenblas" \
		--with-sample-datadir="${LOCALBASE}/share/coin/Data/Sample" \
		--with-netlib-datadir="${LOCALBASE}/share/coin/Data/Netlib" \
		--with-coinutils-incdir="${LOCALBASE}/include/coin" --with-coinutils-lib="${LOCALBASE}/lib/libCoinUtils.so"
		# Incompatible with optional dependencies glpk and SoPlex: https://projects.coin-or.org/Osi/ticket/117 https://projects.coin-or.org/Osi/ticket/118
USE_LDCONFIG=	yes

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/coin

.include <bsd.port.mk>

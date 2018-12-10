# $FreeBSD$

PORTNAME=	CoinUtils
DISTVERSION=	2.10.14
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME}/
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities for COIN-OR project

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/CoinUtils/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		libglpk.so:math/glpk \
		libopenblas.so:math/openblas

USES=		fortran gmake libtool localbase:ldflags pkgconfig zip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas-lib="-lopenblas" --with-lapack-lib="-lopenblas" --with-glpk-lib="-lglpk"
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/coin

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/doc/CoinUtils/LICENSE

.include <bsd.port.mk>

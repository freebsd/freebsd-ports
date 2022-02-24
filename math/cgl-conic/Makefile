PORTNAME=	cgl-conic
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.0.0-6
PORTREVISION=	2
DISTVERSIONSUFFIX=	-gc96de60
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Strategies for conic problems for COIN-OR Cut Generation

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libCoinUtils.so:math/coinutils \
		libipopt.so:math/ipopt \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas \
		libOsiConic.so:math/osi-conic \
		libOsiIpopt.so:math/osiipopt \
		libOsi.so:math/osi

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	aykutbulut
GH_PROJECT=	CGL-CONIC

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

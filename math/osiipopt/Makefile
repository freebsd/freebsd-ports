PORTNAME=	osiipopt
DISTVERSIONPREFIX=	releases/
DISTVERSION=	0.1-8
PORTREVISION=	3
DISTVERSIONSUFFIX=	-gc808091
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Conic solver interface for Ipopt
WWW=		https://github.com/aykutbulut/OsiIpopt

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		libCoinUtils.so:math/coinutils \
		libipopt.so:math/ipopt \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libOsiConic.so:math/osi-conic

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	aykutbulut
GH_PROJECT=	OsiIpopt

GNU_CONFIGURE=	yes

MAKE_ARGS=	FREEBSD_STAGEDIR=${STAGEDIR}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

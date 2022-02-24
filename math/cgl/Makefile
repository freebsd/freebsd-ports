PORTNAME=	cgl
DISTVERSIONPREFIX=	releases/
DISTVERSION=	0.60.4
PORTREVISION=	2
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of cut generators for COIN-OR packages that use cuts

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Cgl/LICENSE

LIB_DEPENDS=	libcoinasl.so:math/asl \
		libblas.so:math/blas \
		libcoinmetis.so:math/ipopt \
		libCoinUtils.so:math/coinutils \
		libClp.so:math/clp \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi

USES=		compiler:c++11-lang gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Cgl

GNU_CONFIGURE=	yes

TEST_TARGET=	test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libCgl.so.*

.include <bsd.port.mk>

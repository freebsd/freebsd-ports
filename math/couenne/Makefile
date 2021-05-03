PORTNAME=	couenne
DISTVERSIONPREFIX=	releases/
DISTVERSION=	0.5.8
PORTREVISION=	3
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convex Over and Under Envelopes for NonliNear Estimation

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Couenne/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libnauty.a:math/nauty
LIB_DEPENDS=	libbonmin.so:math/bonmin \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libipopt.so:math/ipopt

USES=		blaslapack:netlib fortran gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Couenne

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-nauty-incdir=${LOCALBASE}/include/nauty --with-nauty-lib=${LOCALBASE}/lib/libnauty.a

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

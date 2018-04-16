# $FreeBSD$

PORTNAME=	cbc
DISTVERSIONPREFIX=	releases/
DISTVERSION=	2.9.9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coin-or Branch and Cut: mixed integer programming solver

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Cbc/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		liblapack.so:math/lapack

USES=		fortran gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Cbc
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>

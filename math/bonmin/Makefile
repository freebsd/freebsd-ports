PORTNAME=	bonmin
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.8.8
PORTREVISION=	3
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Basic Open-source Nonlinear Mixed INteger programming

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Bonmin/LICENSE

LIB_DEPENDS=	libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libCoinUtils.so:math/coinutils \
		libipopt.so:math/ipopt \
		libopenblas.so:math/openblas

USES=		blaslapack compiler:c++11-lang gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Bonmin

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	test

SUB_FILES=	${PORTNAME}.msc
SUB_LIST=	PORTVERSION=${PORTVERSION}

post-install:
	# install MiniZinc configuration file
	${MKDIR} ${STAGEDIR}${PREFIX}/share/minizinc/solvers
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.msc ${STAGEDIR}${PREFIX}/share/minizinc/solvers

.include <bsd.port.mk>

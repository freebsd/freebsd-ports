# $FreeBSD$

PORTNAME=	4ti2
DISTVERSIONPREFIX=	Release_
DISTVERSION=	1_6_9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solve algebraic, geometric, combinatorial problems on linear spaces

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libglpk.so:math/glpk \
		libgmp.so:math/gmp

USES=		autoreconf compiler:c++11-lang gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-shared --with-glpk=${LOCALBASE} --with-gmp=${LOCALBASE}
USE_GITHUB=	yes
USE_LDCONFIG=	yes

TEST_TARGET=	check # tests fail to run: https://github.com/4ti2/4ti2/issues/26

.include <bsd.port.mk>

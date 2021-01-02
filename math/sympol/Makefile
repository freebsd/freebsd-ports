# $FreeBSD$

PORTNAME=	sympol
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library and tool to work with symmetric polyhedra

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	permlib>0:math/permlib
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libcddgmp.so:math/cddlib \
		libgmp.so:math/gmp

USES=		cmake compiler:c++11-lang eigen:3 localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	tremlin
GH_PROJECT=	SymPol

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcddgmp.so

.include <bsd.port.mk>

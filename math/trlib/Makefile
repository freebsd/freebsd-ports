PORTNAME=	trlib
DISTVERSION=	g20211004
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Trust Region Subproblem Solver Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas
TEST_DEPENDS=	check>0:devel/check \
		gsed:textproc/gsed \
		valgrind:devel/valgrind

USES=		cmake:testing pkgconfig localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	felixlen
GH_TAGNAME=	f168b59

# some tests fail, see https://github.com/felixlen/trlib/issues/16

.include <bsd.port.mk>

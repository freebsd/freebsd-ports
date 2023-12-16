PORTNAME=	trlib
DISTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Trust Region Subproblem Solver Library
WWW=		https://github.com/felixlen/trlib

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

# all valgrind tests fail, see https://github.com/felixlen/trlib/issues/16, due to https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=259294

.include <bsd.port.mk>

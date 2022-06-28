PORTNAME=	lean
DISTVERSIONPREFIX=	v
DISTVERSION=	3.44.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover-community

WRKSRC_SUBDIR=	src

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>

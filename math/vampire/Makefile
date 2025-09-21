PORTNAME=	vampire
DISTVERSIONPREFIX=	v
DISTVERSION=	4.9casc2024
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic theorem prover
WWW=		https://vprover.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BROKEN_armv7=	error: static_assert failed due to requirement 'sizeof(void *) == 8'
BROKEN_i386=	error: static_assert failed due to requirement 'sizeof(void *) == 8'
BROKEN_powerpc=	error: static_assert failed due to requirement 'sizeof(void *) == 8'

LIB_DEPENDS=	libz3.so:math/z3

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	vprover

CMAKE_ARGS=	-DCMAKE_BUILD_HOL=On # code is broken w/out this
CMAKE_ARGS+=	-DZ3_DIR=${WRKSRC}/z3

LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^.*[1-9]\.[1-9].*$$ # prevent tags like sledgehammerScheds

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${PORTNAME}* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

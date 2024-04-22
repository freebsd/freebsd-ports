PORTNAME=	vampire
DISTVERSIONPREFIX=	vHO
DISTVERSION=	4.8
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic theorem prover
WWW=		https://vprover.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BROKEN_armv7=	error: static_assert failed due to requirement 'sizeof(void *) == 8'
BROKEN_i386=	error: static_assert failed due to requirement 'sizeof(void *) == 8'
BROKEN_powerpc=	error: static_assert failed due to requirement 'sizeof(void *) == 8'

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	vprover

CMAKE_ARGS=	-DCMAKE_BUILD_HOL=On # code is broken w/out this

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^.*[1-9]\.[1-9].*$$ # prevent tags like sledgehammerScheds

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${PORTNAME}* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

PORTNAME=	dimod
DISTVERSION=	0.12.23
CATEGORIES=	science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Shared API for QUBO/Ising samplers
WWW=		https://github.com/dwavesystems/dimod

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	meson>0:devel/meson

USES=		compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

NO_BUILD=	yes
NO_ARCH=	yes

BINARY_ALIAS=	g++=${CXX} git=true

do-install:
	cd ${WRKSRC}/dimod/include && \
		${COPYTREE_SHARE} dimod ${STAGEDIR}${PREFIX}/include

pre-test:
	@if [ ! -d ${WRKSRC}/builddir ]; then \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} meson setup builddir -Dbuild-tests=enabled -Dbuild-python=false; \
	fi
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} meson compile -C builddir

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} meson test -C builddir --verbose

# tests as of 0.12.23: All tests passed (104295 assertions in 35 test cases)

.include <bsd.port.mk>

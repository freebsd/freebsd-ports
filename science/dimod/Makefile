PORTNAME=	dimod
DISTVERSION=	0.11.5
CATEGORIES=	science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Shared API for QUBO/Ising samplers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems
GH_TUPLE=	catchorg:Catch2:f0dc4d9:catch/testscpp/Catch2

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/dimod/iterators.h \
		include/dimod/lp.h \
		include/dimod/quadratic_model.h \
		include/dimod/utils.h

BINARY_ALIAS=	g++=${CXX} git=true

do-install:
	cd ${WRKSRC}/dimod/include && \
		${COPYTREE_SHARE} dimod ${STAGEDIR}${PREFIX}/include

do-test: # tests fail to compile, see https://github.com/dwavesystems/dimod/issues/1238
	@cd ${WRKSRC}/testscpp && ${SETENV} ${MAKE_ENV} ${MAKE}

.include <bsd.port.mk>

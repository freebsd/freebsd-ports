PORTNAME=	dwave-preprocessing
DISTVERSION=	0.5.4
CATEGORIES=	science # quantum-computing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Preprocessing tools to aid in solving binary quadratic models
WWW=		https://github.com/dwavesystems/dwave-preprocessing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dimod>0:science/dimod
TEST_DEPENDS=	catch>0:devel/catch \
		spdlog>0:devel/spdlog

USES=		compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

CXXFLAGS+=	`pkg-config --cflags catch2 spdlog`
LDFLAGS+=	`pkg-config --libs catch2 spdlog`

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/dwave-preprocessing/fix_variables.hpp \
		include/dwave-preprocessing/helper_data_structures.hpp \
		include/dwave-preprocessing/helper_graph_algorithms.hpp \
		include/dwave-preprocessing/implication_network.hpp \
		include/dwave-preprocessing/mapping_policy.hpp \
		include/dwave-preprocessing/posiform_info.hpp \
		include/dwave-preprocessing/push_relabel.hpp

BINARY_ALIAS=	git=true

do-install:
	cd ${WRKSRC}/dwave/preprocessing/include && \
		${COPYTREE_SHARE} dwave-preprocessing ${STAGEDIR}${PREFIX}/include

do-test: # tests fail to link, see https://github.com/dwavesystems/dwave-preprocessing/issues/119
	@cd ${WRKSRC}/testscpp && ${SETENV} ${MAKE_ENV} ${MAKE} DIMOD="-I${LOCALBASE}/include"

.include <bsd.port.mk>

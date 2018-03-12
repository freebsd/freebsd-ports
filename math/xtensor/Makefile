# $FreeBSD$

PORTNAME=	xtensor
DISTVERSION=	0.15.4
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-dimensional arrays with broadcasting and lazy computing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	QuantStack
GH_TUPLE=	QuantStack:xtl:0.4.4:xtl/xtl
NO_BUILD=	yes
NO_ARCH=	yes

post-install:
	cd ${WRKSRC}/xtl/include && ${COPYTREE_SHARE} xtl ${STAGEDIR}${PREFIX}/include

do-test: # 1 test is known to fail: https://github.com/QuantStack/xtensor/issues/674
	@${RLN} ${STAGEDIR}${PREFIX}/include ${WRKSRC}/test/staged-include
	@cd ${WRKSRC}/test && \
		${CMAKE_BIN} ${CMAKE_ARGS} . && \
		${MAKE_CMD} && \
		${MAKE_CMD} xtest

.include <bsd.port.mk>

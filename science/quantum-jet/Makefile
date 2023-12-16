PORTNAME=	quantum-jet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2-2
PORTREVISION=	2
DISTVERSIONSUFFIX=	-g99c55ce
CATEGORIES=	science # quantum-computing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform header-only library for simulating quantum circuits
WWW=		https://github.com/XanaduAI/jet

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openblas>0:math/openblas
RUN_DEPENDS=	taskflow>0:devel/taskflow \
		openblas>0:math/openblas
TEST_DEPENDS=	git:devel/git

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	XanaduAI
GH_PROJECT=	jet

CMAKE_TESTING_ON=	BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

do-configure: # no configure because it clones the taskflow repository
	@${NADA}

do-install: # tests fail to compile, see https://github.com/XanaduAI/jet/issues/77
	@cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>

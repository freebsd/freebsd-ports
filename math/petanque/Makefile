PORTNAME=	petanque
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.1.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library that helps manipulate symbolic boolean expressions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	quarkslab
GH_PROJECT=	arybo

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	WITH_TESTS # tests fail to find TBB, see https://github.com/quarkslab/arybo/issues/29

.include <bsd.port.mk>

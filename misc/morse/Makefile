PORTNAME=	morse
DISTVERSION=	1.4-154
DISTVERSIONSUFFIX=	-g53f9eaa8
CATEGORIES=	misc
PKGNAMESUFFIX=	-robotics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular OpenRobots Simulation Engine
WWW=		https://morse-simulator.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-simulator
SHEBANG_FILES=	bin/morse_inspector

CMAKE_ARGS=	-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

.include <bsd.port.mk>

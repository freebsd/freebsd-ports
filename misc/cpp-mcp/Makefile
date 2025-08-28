PORTNAME=	cpp-mcp
PORTVERSION=	g20250523
CATEGORIES=	misc devel # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight C++ MCP (Model Context Protocol) SDK
WWW=		https://github.com/hkr04/cpp-mcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	hkr04
GH_TAGNAME=	86856a2

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>

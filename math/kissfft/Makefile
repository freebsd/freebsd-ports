PORTNAME=	kissfft
PORTVERSION=	131.2.0
CATEGORIES=	math

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mixed-radix Fast Fourier Transform
WWW=		https://github.com/mborgerding/kissfft/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	mborgerding

USE_LDCONFIG=	yes

CMAKE_OFF=	KISSFFT_TEST

OPTIONS_DEFINE=		TOOLS
OPTIONS_SUB=		yes

TOOLS_USES=		pkgconfig
TOOLS_LIB_DEPENDS=	libpng.so:graphics/png
TOOLS_CMAKE_BOOL=	KISSFFT_TOOLS

.include <bsd.port.mk>

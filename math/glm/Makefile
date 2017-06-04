# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	glm
PORTVERSION=	0.9.8.4
PORTEPOCH=	1
CATEGORIES=	math graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

USE_GITHUB=	yes
GH_ACCOUNT=	g-truc

NO_ARCH=	yes
NO_BUILD=	yes

USES=		cmake:outsource pkgconfig

.ifndef MAINTAINER_MODE
CMAKE_ARGS=	-DGLM_TEST_ENABLE:BOOL=OFF
.endif

.include <bsd.port.mk>

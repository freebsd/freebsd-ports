# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	glm
PORTVERSION=	0.9.7.1
PORTEPOCH=	1
CATEGORIES=	math graphics

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

USE_GITHUB=	yes
GH_ACCOUNT=	g-truc

USES=		dos2unix
DOS2UNIX_FILES=	glm/detail/dummy.cpp
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/include '( ! -name *.orig )'

.include <bsd.port.mk>

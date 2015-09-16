# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	glm
PORTVERSION=	0.9.6.3
PORTEPOCH=	1
CATEGORIES=	math graphics
MASTER_SITES=	SF/ogl-math/${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

USES=		zip dos2unix
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/include '( ! -name *.orig )'

.include <bsd.port.mk>

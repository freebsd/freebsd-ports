# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	glm
PORTVERSION=	0.9.5.2
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ogl-math/${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
		cd ${WRKSRC} && ${FIND} glm -print -depth | ${CPIO} -pdm ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>

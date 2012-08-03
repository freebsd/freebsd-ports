# New ports collection makefile for:   	glm
# Date created:         Aug 03 2012
# Whom:                 demon@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	glm
PORTVERSION=	0.9.3.4
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ogl-math/${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
		cd ${WRKSRC} && ${FIND} glm -print -depth | ${CPIO} -pdm ${PREFIX}/include/

.include <bsd.port.mk>

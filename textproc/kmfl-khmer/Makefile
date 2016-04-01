# Created by: Kuan-Chung Chiu <buganini@gmail.com>
# $FreeBSD$

PORTNAME=	khmer
PORTVERSION=	1.0
CATEGORIES=	textproc
PKGNAMEPREFIX=	kmfl-

MAINTAINER=	buganini@gmail.com
COMMENT=	KMFL SCIM IMEngine keyboard for Khmer language

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	kmfl-${PORTNAME}
NO_BUILD=	yes
WRKSRC_SUBDIR=	kmfl

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

PLIST_FILES=	${KMFL_DIR}/khmer.kmn \
		${KMFL_ICONS_DIR}/khmer.bmp

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}

.include <bsd.port.mk>

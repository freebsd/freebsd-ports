# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-varamozhi-malayalam
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/varamozhi/2%20Mozhi%20Keyman%20-%20Input%20Method/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	mozhi_${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL Malayalam keyboard according to the Mozhi scheme

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

USES=		dos2unix zip
DOS2UNIX_FILES=	mozhi_1.1.0.kmn
NO_BUILD=	yes

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message

PLIST_FILES=	${KMFL_DIR}/mozhi_1.1.0.kmn \
		${KMFL_ICONS_DIR}/mozhi.bmp

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}

.include <bsd.port.mk>

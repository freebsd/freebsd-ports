# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-yi
PORTVERSION=	20020903
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=SILYi12OFL_Src&filename=/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	SILYiOFL1.2Src
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL Unicode keyboard for standardized Yi script

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

WRKSRC=		${WRKDIR}
USES=		dos2unix zip
DOS2UNIX_FILES=	SourceFiles/Yi7.kmn
NO_BUILD=	yes

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message

PLIST_FILES=	${KMFL_DIR}/Yi7.kmn \
		${KMFL_ICONS_DIR}/YiPinYin.bmp

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/SourceFiles/*.kmn ${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/SourceFiles/*.bmp ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}

.include <bsd.port.mk>

# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-panafrican-latin
PORTVERSION=	20090831
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=AfricaKeyboardDead2009&filename=/:1 \
		http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=AfricaKeyboardUS2009&filename=/:2 \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/:1,2
DISTFILES=	AfricaKeyboardDead.zip:1 AfricaKeyboardUS.zip:2
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL keyboard for African Latin writing systems

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

WRKSRC=		${WRKDIR}
USES=		dos2unix zip
DOS2UNIX_FILES=	PanAfricaMnemonic/AfricaDeadKey.kmn \
		PanAfricaUSlayout/AfricaUS.kmn
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
DOCSDIR=	share/doc/kmfl/${PORTNAME}
DOCSLIST=	PanAfricaMnemonic/SIL\ Unicode\ Keyboard\ Chart\ for\ Africa\ using\ deadkeys.pdf \
		PanAfricaUSlayout/SIL\ Unicode\ Keyboard\ Chart\ for\ Africa\ using\ shiftkeys.pdf

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message

post-patch:
		@${REINPLACE_CMD} -e 's|^BITMAP AFR|BITMAP AFR.bmp|' \
			${WRKSRC}/PanAfricaMnemonic/AfricaDeadKey.kmn \
			${WRKSRC}/PanAfricaUSlayout/AfricaUS.kmn

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/PanAfricaMnemonic/*.kmn \
		${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/PanAfricaUSlayout/*.kmn \
		${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/PanAfricaMnemonic/*.bmp \
		${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${DOCSDIR:S,/${PORTNAME},,} \
		${STAGEDIR}${PREFIX}/${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} "${WRKSRC}/$$doc" ${STAGEDIR}${PREFIX}/${DOCSDIR} ; \
	done

.include <bsd.port.mk>

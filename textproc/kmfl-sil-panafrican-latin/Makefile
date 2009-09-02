# New ports collection makefile for:	scim-kmfl-sil-panafrican-latin
# Date created:		1 September 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	scim-kmfl-sil-panafrican-latin
PORTVERSION=	20090831
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=AfricaKeyboardDead2009\&filename=/:1 \
		http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=AfricaKeyboardUS2009\&filename=/:2 \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/:1,2
DISTFILES=	AfricaKeyboardDead.zip:1 AfricaKeyboardUS.zip:2
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM KMFL IMEngine keyboard for African Latin writing systems

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
 		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/kmfl.so:${PORTSDIR}/textproc/scim-kmfl-imengine

WRKSRC=		${WRKDIR}
USE_DOS2UNIX=	PanAfricaMnemonic/AfricaDeadKey.kmn \
		PanAfricaUSlayout/AfricaUS.kmn
NO_BUILD=	yes
USE_ZIP=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
SCIM_KMFL_DIR=	share/scim/kmfl
SCIM_KMFL_ICONS_DIR=	share/scim/kmfl/icons

post-patch:
		@${REINPLACE_CMD} -e 's|^BITMAP AFR|BITMAP AFR.bmp|' \
			${WRKSRC}/PanAfricaMnemonic/AfricaDeadKey.kmn \
			${WRKSRC}/PanAfricaUSlayout/AfricaUS.kmn

PORTDOCS=	*
DOCSLIST=	PanAfricaMnemonic/SIL\ Unicode\ Keyboard\ Chart\ for\ Africa\ using\ deadkeys.pdf \
		PanAfricaUSlayout/SIL\ Unicode\ Keyboard\ Chart\ for\ Africa\ using\ shiftkeys.pdf

PLIST_FILES=	${SCIM_KMFL_DIR}/AfricaDeadKey.kmn \
		${SCIM_KMFL_DIR}/AfricaUS.kmn \
		${SCIM_KMFL_ICONS_DIR}/AFR.bmp

do-install:
	${INSTALL_DATA} ${WRKSRC}/PanAfricaMnemonic/*.kmn \
		${LOCALBASE}/${SCIM_KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/PanAfricaUSlayout/*.kmn \
		${LOCALBASE}/${SCIM_KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/PanAfricaMnemonic/*.bmp \
		${LOCALBASE}/${SCIM_KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} "${WRKSRC}/$$doc" ${DOCSDIR} ; \
	done
.endif

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Others\" in your SCIM menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "  The documentation is installed into:"
	@${ECHO_MSG} "    ${DOCSDIR}"
.endif
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>

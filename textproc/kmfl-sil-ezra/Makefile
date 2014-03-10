# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-ezra
PORTVERSION=	2.4
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=EzraSIL251_Src.zip\&filename=/:1 \
		http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=EzraSIL2.5Keying\&filename=/:2 \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/:1,2
DISTFILES=	EzraSIL251_Src.zip:1 \
		Keying+in+Hebrew.pdf:2
DIST_SUBDIR=	kmfl
EXTRACT_ONLY=	EzraSIL251_Src.zip

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL keyboard for Unicode Biblical Hebrew

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

WRKSRC=		${WRKDIR}/EzraSIL2.51
USES=		dos2unix zip
DOS2UNIX_FILES=	Keyman/EZRAUNI24.KMN
NO_BUILD=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

PORTDOCS=	*
DOCSLIST=	${WRKSRC}/Licenses.txt ${WRKSRC}/README.txt \
		${WRKSRC}/WordDocs/Ezra\ SIL\ Keyboard\ Chart.doc \
		${DISTDIR}/${DIST_SUBDIR}/Keying+in+Hebrew.pdf \
		${WRKSRC}/WordDocs/Simplified\ keyboard\ chart.doc

PLIST_FILES=	${KMFL_DIR}/EZRAUNI24.kmn \
		${KMFL_ICONS_DIR}/HEBDISPY.bmp \
		${KMFL_ICONS_DIR}/alef.bmp
PLIST_DIRSTRY=	${KMFL_ICONS_DIR} \
		${KMFL_DIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${LOCALBASE}/${KMFL_DIR} ${LOCALBASE}/${KMFL_ICONS_DIR}
	${CP} -f ${WRKSRC}/Keyman/EZRAUNI24.KMN ${WRKSRC}/Keyman/EZRAUNI24.kmn
	${INSTALL_DATA} ${WRKSRC}/Keyman/*.kmn ${LOCALBASE}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/Keyman/*.bmp ${LOCALBASE}/${KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} "$$doc" ${DOCSDIR} ; \
	done
.endif

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Hebrew\" in your SCIM/IBus menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "  The documentation is installed into:"
	@${ECHO_MSG} "    ${DOCSDIR}"
	@${ECHO_MSG} "  Please note that some documentation files are"
	@${ECHO_MSG} "  officially released in proprietary formats only and"
	@${ECHO_MSG} "  that they are installed as such."
.endif
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>

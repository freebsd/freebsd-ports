# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-ezra
PORTVERSION=	2.4
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=EzraSIL251_Src.zip&filename=/:1 \
		http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=EzraSIL2.5Keying&filename=/:2 \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/:1,2
DISTFILES=	EzraSIL251_Src.zip:1 \
		Keying+in+Hebrew.pdf:2
DIST_SUBDIR=	kmfl
EXTRACT_ONLY=	EzraSIL251_Src.zip

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL keyboard for Unicode Biblical Hebrew

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

WRKSRC=		${WRKDIR}/EzraSIL2.51
USES=		dos2unix zip
DOS2UNIX_FILES=	Keyman/EZRAUNI24.KMN
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
DOCSLIST=	${WRKSRC}/Licenses.txt ${WRKSRC}/README.txt \
		${WRKSRC}/WordDocs/Ezra\ SIL\ Keyboard\ Chart.doc \
		${DISTDIR}/${DIST_SUBDIR}/Keying+in+Hebrew.pdf \
		${WRKSRC}/WordDocs/Simplified\ keyboard\ chart.doc

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${CP} -f ${WRKSRC}/Keyman/EZRAUNI24.KMN ${WRKSRC}/Keyman/EZRAUNI24.kmn
	${INSTALL_DATA} ${WRKSRC}/Keyman/*.kmn ${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/Keyman/*.bmp ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} "$$doc" ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.mk>

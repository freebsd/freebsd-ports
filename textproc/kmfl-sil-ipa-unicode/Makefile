# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-ipa-unicode
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=IPAUni_12_Src\&filename=/:1 \
		http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=IPAUni_12.pdf\&filename=/:2
DISTFILES=	IPAUni_Src12.zip:1 \
   		IPA+Unicode+5.1_ver+1.2_KMN.pdf:2
DIST_SUBDIR=	kmfl
EXTRACT_ONLY=	IPAUni_Src12.zip

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	IPA Unicode 5.1 mnemonic keyboard for KMFL IMEngine

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

USES=		dos2unix zip
WRKSRC=		${WRKDIR}/IPA12
DOS2UNIX_FILES=	IPAUni12.kmn
NO_BUILD=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message
PORTDOCS=	*
DOCSLIST=	${WRKSRC}/welcome.htm \
		${DISTDIR}/${DIST_SUBDIR}/IPA+Unicode+5.1_ver+1.2_KMN.pdf
PLIST_FILES=	${KMFL_DIR}/IPAUni12.kmn \
		${KMFL_ICONS_DIR}/ipa.bmp \
		${KMFL_ICONS_DIR}/sil.bmp
PLIST_DIRSTRY=	${KMFL_ICONS_DIR} \
		${KMFL_DIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${LOCALBASE}/${KMFL_DIR} ${LOCALBASE}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${LOCALBASE}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${LOCALBASE}/${KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} $$doc ${DOCSDIR} ; \
	done
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

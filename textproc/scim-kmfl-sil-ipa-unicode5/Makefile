# New ports collection makefile for:	scim-kmfl-sil-ipa-unicode5
# Date created:		10 October 2007
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$

PORTNAME=	scim-kmfl-sil-ipa-unicode5
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=IPAUni_12_Src\&filename=/:1 \
		http://scripts.sil.org/cms/scripts/render_download.php\?site_id=nrsi\&format=file\&media_id=IPAUni_12.pdf\&filename=/:2
DISTFILES=	IPAUni_Src12.zip:1 \
   		IPA+Unicode+5.1_ver+1.2_KMN.pdf:2
DIST_SUBDIR=	kmfl
EXTRACT_ONLY=	IPAUni_Src12.zip

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	IPA Unicode 5.1 mnemonic keyboard for KMFL IMEngine of SCIM

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
 		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/kmfl.so:${PORTSDIR}/textproc/scim-kmfl-imengine

WRKSRC=		${WRKDIR}/IPA12
USE_DOS2UNIX=	IPAUni12.kmn
NO_BUILD=	yes
USE_ZIP=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
SCIM_KMFL_DIR=	share/scim/kmfl
SCIM_KMFL_ICONS_DIR=	share/scim/kmfl/icons

SUB_FILES=	pkg-message
PORTDOCS=	*
DOCSLIST=	${WRKSRC}/welcome.htm \
		${DISTDIR}/${DIST_SUBDIR}/IPA+Unicode+5.1_ver+1.2_KMN.pdf
PLIST_FILES=	${SCIM_KMFL_DIR}/IPAUni12.kmn \
		${SCIM_KMFL_ICONS_DIR}/ipa.bmp \
		${SCIM_KMFL_ICONS_DIR}/sil.bmp

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${LOCALBASE}/${SCIM_KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${LOCALBASE}/${SCIM_KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} $$doc ${DOCSDIR} ; \
	done
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

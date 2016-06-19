# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-ipa-unicode
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=IPAUni_12_Src&filename=/:1 \
		http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=IPAUni_12.pdf&filename=/:2
DISTFILES=	IPAUni_Src12.zip:1 \
		IPA+Unicode+5.1_ver+1.2_KMN.pdf:2
DIST_SUBDIR=	kmfl
EXTRACT_ONLY=	IPAUni_Src12.zip

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	IPA Unicode 5.1 mnemonic keyboard for KMFL IMEngine

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

USES=		dos2unix zip
WRKSRC=		${WRKDIR}/IPA12
DOS2UNIX_FILES=	IPAUni12.kmn
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
DOCSDIR=	share/doc/kmfl/${PORTNAME}
DOCSLIST=	${WRKSRC}/welcome.htm \
		${DISTDIR}/${DIST_SUBDIR}/IPA+Unicode+5.1_ver+1.2_KMN.pdf

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${DOCSDIR:S,/${PORTNAME},,} \
		${STAGEDIR}${PREFIX}/${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} $$doc ${STAGEDIR}${PREFIX}/${DOCSDIR} ; \
	done

.include <bsd.port.mk>

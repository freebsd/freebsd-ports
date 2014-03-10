# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-yi
PORTVERSION=	20020903
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=SILYi12OFL_Src&filename=/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	SILYiOFL1.2Src
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL Unicode keyboard for standardized Yi script

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

WRKSRC=		${WRKDIR}
USES=		dos2unix zip
DOS2UNIX_FILES=	SourceFiles/Yi7.kmn
NO_BUILD=	yes

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

PLIST_FILES=	${KMFL_DIR}/Yi7.kmn \
		${KMFL_ICONS_DIR}/YiPinYin.bmp
PLIST_DIRSTRY=	${KMFL_ICONS_DIR} \
		${KMFL_DIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${LOCALBASE}/${KMFL_DIR} ${LOCALBASE}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/SourceFiles/*.kmn ${LOCALBASE}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/SourceFiles/*.bmp ${LOCALBASE}/${KMFL_ICONS_DIR}

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Others\" in your SCIM/IBus menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
	@${ECHO_MSG}
	@${ECHO_MSG} "  At the moment, this keyboard has no documentation."
	@${ECHO_MSG} "  As a general rule, type the Pinyin romanization for"
	@${ECHO_MSG} "  that syllable, followed by a space. For punctuation,"
	@${ECHO_MSG} "  try usual punctuation keystrokes."
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>

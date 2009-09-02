# New ports collection makefile for:	scim-kmfl-sil-yi
# Date created:		1 September 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	scim-kmfl-sil-yi
PORTVERSION=	20020903
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=SILYi12OFL_Src&filename=/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/kmfl/
DISTNAME=	SILYiOFL1.2Src
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM KMFL IMEngine Unicode keyboard for standardized Yi script

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
 		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/kmfl.so:${PORTSDIR}/textproc/scim-kmfl-imengine

WRKSRC=		${WRKDIR}
USE_DOS2UNIX=	SourceFiles/Yi7.kmn
NO_BUILD=	yes
USE_ZIP=	yes

SCIM_KMFL_DIR=	share/scim/kmfl
SCIM_KMFL_ICONS_DIR=	share/scim/kmfl/icons

PLIST_FILES=	${SCIM_KMFL_DIR}/Yi7.kmn \
		${SCIM_KMFL_ICONS_DIR}/YiPinYin.bmp

do-install:
	${INSTALL_DATA} ${WRKSRC}/SourceFiles/*.kmn ${LOCALBASE}/${SCIM_KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/SourceFiles/*.bmp ${LOCALBASE}/${SCIM_KMFL_ICONS_DIR}

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Others\" in your SCIM menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
	@${ECHO_MSG}
	@${ECHO_MSG} "  At the moment, this keyboard has no documentation."
	@${ECHO_MSG} "  As a general rule, type the Pinyin romanization for"
	@${ECHO_MSG} "  that syllable, followed by a space. For punctuation,"
	@${ECHO_MSG} "  try usual punctuation keystrokes."
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>

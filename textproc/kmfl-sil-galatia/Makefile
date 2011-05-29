# New ports collection makefile for:	scim-kmfl-sil-galatia
# Date created:		24 August 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	kmfl-sil-galatia
PORTVERSION=	1.02
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=GrkPolyComp_Src&filename=/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	GrkPolyComp_Src
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL Unicode keyboard for typesetting Ancient Greek

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

WRKSRC=		${WRKDIR}/GrkPolyComp_Src
USE_DOS2UNIX=	GrkPolyComp.KMN
NO_BUILD=	yes
USE_ZIP=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

PORTDOCS=	*
DOCSLIST=	Greek\ Poly\ Comp\ Kbrd\ Layout.pdf \
		welcome.htm

PLIST_FILES=	${KMFL_DIR}/GrkPolyComp.kmn \
		${KMFL_ICONS_DIR}/ALPHA.bmp
PLIST_DIRSTRY=	${KMFL_ICONS_DIR} \
		${KMFL_DIR}

do-install:
	${MKDIR} ${LOCALBASE}/${KMFL_DIR} ${LOCALBASE}/${KMFL_ICONS_DIR}
	${CP} -f ${WRKSRC}/GrkPolyComp.KMN ${WRKSRC}/GrkPolyComp.kmn
	${INSTALL_DATA} ${WRKSRC}/GrkPolyComp.kmn ${LOCALBASE}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/ALPHA.bmp ${LOCALBASE}/${KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} "${WRKSRC}/$$doc" ${DOCSDIR} ; \
	done
.endif

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Greek\" in your SCIM/IBus menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "  The documentation is installed into:"
	@${ECHO_MSG} "    ${DOCSDIR}"
.endif
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>

# New ports collection makefile for:	scim-kmfl-sil-galatia
# Date created:		24 August 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	scim-kmfl-sil-galatia
PORTVERSION=	1.02
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=GrkPolyComp_Src&filename=/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	GrkPolyComp_Src
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM KMFL IMEngine Unicode keyboard for typesetting Ancient Greek

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
 		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/kmfl.so:${PORTSDIR}/textproc/scim-kmfl-imengine

WRKSRC=		${WRKDIR}/GrkPolyComp_Src
USE_DOS2UNIX=	GrkPolyComp.KMN
NO_BUILD=	yes
USE_ZIP=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
SCIM_KMFL_DIR=	share/scim/kmfl
SCIM_KMFL_ICONS_DIR=	share/scim/kmfl/icons

PORTDOCS=	*
DOCSLIST=	Greek\ Poly\ Comp\ Kbrd\ Layout.pdf \
		welcome.htm

PLIST_FILES=	${SCIM_KMFL_DIR}/GrkPolyComp.kmn \
		${SCIM_KMFL_ICONS_DIR}/ALPHA.bmp

do-install:
	${CP} -f ${WRKSRC}/GrkPolyComp.KMN ${WRKSRC}/GrkPolyComp.kmn
	${INSTALL_DATA} ${WRKSRC}/GrkPolyComp.kmn ${LOCALBASE}/${SCIM_KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/ALPHA.bmp ${LOCALBASE}/${SCIM_KMFL_ICONS_DIR}
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

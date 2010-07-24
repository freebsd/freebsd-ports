# New ports collection makefile for:	scim-kmfl-european-latin
# Date created:		27 June 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$

PORTNAME=	scim-kmfl-european-latin
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://eurolatin.keymankeyboards.com/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DISTNAME=	eurolatin-${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Paneuropean Latin KMFL SCIM IMEngine keyboard covering 42 languages

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
 		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/kmfl.so:${PORTSDIR}/textproc/scim-kmfl-imengine

NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	european.kmn
NO_BUILD=	yes
USE_ZIP=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
SCIM_KMFL_DIR=	share/scim/kmfl
SCIM_KMFL_ICONS_DIR=	share/scim/kmfl/icons

PORTDOCS=	*
DOCSLIST=	eurolatin12.pdf european.html licence.txt readme.html \
	       	welcome.htm
PLIST_FILES=	${SCIM_KMFL_DIR}/european.kmn \
		${SCIM_KMFL_ICONS_DIR}/european.bmp \
		${SCIM_KMFL_ICONS_DIR}/latin.bmp \
		${SCIM_KMFL_ICONS_DIR}/latin.ico

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${LOCALBASE}/${SCIM_KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${WRKSRC}/*.ico \
	       ${LOCALBASE}/${SCIM_KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$doc ${DOCSDIR} ; \
	done
.endif

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Others\" in your SCIM menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "  The PDF documentation for use of the European Latin"
	@${ECHO_MSG} "  Keyboard can be found in:"
	@${ECHO_MSG} "  ${PREFIX}/share/doc/kmfl/scim-kmfl-european-latin/"
.endif
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>

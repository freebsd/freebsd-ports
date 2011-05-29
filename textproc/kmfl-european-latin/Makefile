# New ports collection makefile for:	scim-kmfl-european-latin
# Date created:		27 June 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$

PORTNAME=	kmfl-european-latin
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://eurolatin.keymankeyboards.com/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DISTNAME=	eurolatin-${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Paneuropean Latin KMFL keyboard covering 42 languages

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	european.kmn
NO_BUILD=	yes
USE_ZIP=	yes

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

PORTDOCS=	*
DOCSLIST=	eurolatin12.pdf european.html licence.txt readme.html \
	       	welcome.htm
PLIST_FILES=	${KMFL_DIR}/european.kmn \
		${KMFL_ICONS_DIR}/european.bmp \
		${KMFL_ICONS_DIR}/latin.bmp \
		${KMFL_ICONS_DIR}/latin.ico
PLIST_DIRSTRY=	${KMFL_ICONS_DIR} \
		${KMFL_DIR}

do-install:
	${MKDIR} ${LOCALBASE}/${KMFL_DIR} ${LOCALBASE}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${LOCALBASE}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${WRKSRC}/*.ico \
	       ${LOCALBASE}/${KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$doc ${DOCSDIR} ; \
	done
.endif

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Others\" in your SCIM/IBus menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "  The PDF documentation for use of the European Latin"
	@${ECHO_MSG} "  Keyboard can be found in:"
	@${ECHO_MSG} "  ${PREFIX}/share/doc/kmfl/${PORTNAME}/"
.endif
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>

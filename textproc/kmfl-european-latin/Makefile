# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-european-latin
PORTVERSION=	1.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.tavultesoft.com/eurolatin/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	eurolatin-source-${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Paneuropean Latin KMFL keyboard covering 120 languages

BUILD_DEPENDS=	base64:${PORTSDIR}/converters/base64
RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

WRKSRC=		${WRKDIR}/EuroLatin\ Source\ Files
USES=		dos2unix zip
DOS2UNIX_FILES=	european.kmn

DOCSDIR_REL=	share/doc/kmfl/${PORTNAME}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

PORTDOCS=	*
DOCSLIST=	EuroLatin\ Keyman\ Desktop\ Keyboard\ Files/eurolatin1.6.pdf \
		EuroLatin\ KeymanWeb\ Keyboard\ Files/european.html \
		licence.txt
PLIST_FILES=	${KMFL_DIR}/european.kmn \
		${KMFL_ICONS_DIR}/latin.png
PLIST_DIRSTRY=	${KMFL_ICONS_DIR} \
		${KMFL_DIR}

NO_STAGE=	yes
do-build:
	base64 -d ${FILESDIR}/latin.png.base64.txt > ${WRKSRC}/latin.png

do-install:
	${MKDIR} ${LOCALBASE}/${KMFL_DIR} ${LOCALBASE}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${LOCALBASE}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/latin.png ${LOCALBASE}/${KMFL_ICONS_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} ${WRKSRC}/"$$doc" ${DOCSDIR} ; \
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

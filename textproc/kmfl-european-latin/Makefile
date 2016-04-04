# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-european-latin
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tavultesoft.com/eurolatin/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	eurolatin-source-${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Paneuropean Latin KMFL keyboard covering 120 languages

BUILD_DEPENDS=	base64:converters/base64
RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

WRKSRC=		${WRKDIR}/EuroLatin\ Source\ Files
USES=		dos2unix zip
DOS2UNIX_FILES=	european.kmn

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
DOCSLIST=	EuroLatin\ Keyman\ Desktop\ Keyboard\ Files/eurolatin1.6.pdf \
		EuroLatin\ KeymanWeb\ Keyboard\ Files/european.html \
		licence.txt

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message

do-build:
	${LOCALBASE}/bin/base64 -d ${FILESDIR}/latin.png.base64.txt > ${WRKSRC}/latin.png

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/latin.png ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} ${WRKSRC}/"$$doc" ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.mk>

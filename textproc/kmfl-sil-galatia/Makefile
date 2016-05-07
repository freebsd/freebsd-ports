# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-sil-galatia
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=${DISTNAME}&filename=/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	GrkPolyCompv${PORTVERSION:S|.||}_Src
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL Unicode keyboard for typesetting Ancient Greek

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

USES=		dos2unix zip
DOS2UNIX_FILES=	GrkPolyCompv${PORTVERSION:S|.||}.KMN
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
DOCSLIST=	Greek\ Poly\ Comp\ Kbrd\ Layout.pdf \
		welcome.htm

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${CP} -f ${WRKSRC}/GrkPolyCompv${PORTVERSION:S|.||}.KMN \
		${WRKSRC}/GrkPolyCompv${PORTVERSION:S|.||}.kmn
	${INSTALL_DATA} ${WRKSRC}/GrkPolyCompv${PORTVERSION:S|.||}.kmn \
		${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/ALPHA.bmp ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} "${WRKSRC}/$$doc" ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.mk>

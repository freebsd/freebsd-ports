# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	3.111
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.carrois.com/wordpress/downloads/${PORTNAME}_3_1/ \
		SF/horia/${CATEGORIES}/${PORTNAME}/
DISTNAME=	${PORTNAME:S|f|F|}Fonts${PORTVERSION:S|.||}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME:S|f|F|}PDF${PORTVERSION:S|.||}${EXTRACT_SUFX} \
		${PORTNAME:S|f|F|}UFO_beta${PORTVERSION:S|.||}${EXTRACT_SUFX} \
		Version_Report.rtf
EXTRACT_ONLY=	${DISTFILES:C|Version.*||}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Sans-serif and monospaced typeface for small screens

LICENSE=	OFL11

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		zip
USE_XORG=	x11
FONTLIBPATH=	lib/X11/fonts
FONTROOTDIR=	${PREFIX}/${FONTLIBPATH}
FONTDIR=	${FONTROOTDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

PORTDOCS=	Version_Report.rtf \
		${PORTNAME:S|f|F|}*.pdf

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	UFO source files

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME:S|f|F|}*${PORTVERSION:S|.||}/OTF/${PORTNAME:S|f|F|}*.otf \
		${STAGEDIR}${FONTDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DISTDIR}/Version_Report.rtf ${WRKSRC}/
	${CP} ${WRKDIR}/${PORTNAME:S|f|F|}PDF${PORTVERSION:S|.||}/${PORTNAME:S|f|F|}*.pdf ${WRKSRC}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKDIR}/${PORTNAME:S|f|F|}UFO_beta${PORTVERSION:S|.||} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

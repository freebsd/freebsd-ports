# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	3.111
PORTREVISION=	1
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

USES=		fonts zip
USE_XORG=	x11
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

PORTDOCS=	Version_Report.rtf \
		${PORTNAME:S|f|F|}*.pdf

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	UFO source files

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME:S|f|F|}*${PORTVERSION:S|.||}/OTF/${PORTNAME:S|f|F|}*.otf \
		${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DISTDIR}/Version_Report.rtf ${WRKSRC}/
	${CP} ${WRKDIR}/${PORTNAME:S|f|F|}PDF${PORTVERSION:S|.||}/${PORTNAME:S|f|F|}*.pdf ${WRKSRC}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKDIR}/${PORTNAME:S|f|F|}UFO_beta${PORTVERSION:S|.||} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

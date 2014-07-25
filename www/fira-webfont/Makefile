# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	3.111
CATEGORIES=	www
MASTER_SITES=	http://www.carrois.com/wordpress/downloads/${PORTNAME}_3_1/ \
		SF/horia/${CATEGORIES}/${PORTNAME}${PKGNAMESUFFIX}/ \
		SF/horia/${CATEGORIES}/${PORTNAME}${PKGNAMESUFFIX}/:bp
PKGNAMESUFFIX=	-webfont
DISTNAME=	${PORTNAME:S|f|F|}Fonts${PORTVERSION:S|.||}
DISTFILES=	${PORTNAME:S|f|F|}Boilerplate${PORTVERSION:S|.||}${EXTRACT_SUFX}:bp \
		${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME:S|f|F|}PDF${PORTVERSION:S|.||}${EXTRACT_SUFX} \
		${PORTNAME:S|f|F|}UFO_beta${PORTVERSION:S|.||}${EXTRACT_SUFX} \
		Version_Report.rtf
EXTRACT_ONLY=	${DISTFILES:C|Version.*||:S|:bp||}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Sans-serif and monospaced Web Font for small screens

LICENSE=	OFL11

USES=		zip
NO_BUILD=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	WWWDIR_REL="${WWWDIR_REL}"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	Version_Report.rtf \
		${PORTNAME:S|f|F|}*.pdf

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	UFO source files

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
.for b in index.html fira.css
	${INSTALL_DATA} \
	${WRKDIR}/${PORTNAME:S|f|F|}Boilerplate${PORTVERSION:S|.||}/${b} \
		${STAGEDIR}${WWWDIR}
.endfor
.for w in eot ttf woff
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${w}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME:S|f|F|}*${PORTVERSION:S|.||}/WEB/${PORTNAME:S|f|F|}*.${w} \
		${STAGEDIR}${WWWDIR}/${w}/
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DISTDIR}/Version_Report.rtf ${WRKSRC}/
	${CP} ${WRKDIR}/${PORTNAME:S|f|F|}PDF${PORTVERSION:S|.||}/${PORTNAME:S|f|F|}*.pdf ${WRKSRC}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKDIR}/${PORTNAME:S|f|F|}UFO_beta${PORTVERSION:S|.||} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

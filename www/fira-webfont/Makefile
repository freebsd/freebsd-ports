# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	4.104
CATEGORIES=	www
MASTER_SITES=	http://www.carrois.com/downloads/%SUBDIR%/:sans,mono \
		SF/horia/${CATEGORIES}/${PORTNAME}${PKGNAMESUFFIX}/%SUBDIR%/:sans,mono,bp
MASTER_SITE_SUBDIR=	${PORTNAME}_4_1/:sans,bp ${PORTNAME}_mono_3_2/:mono
PKGNAMESUFFIX=	-webfont
DISTNAME=	${PORTNAME:S|f|F|}
DISTFILES=	${DISTNAME}Boilerplate${PORTVERSION:S|.||}${EXTRACT_SUFX}:bp \
		${DISTNAME}Fonts${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
		${DISTNAME}MonoFonts${MONO_VERSION}${EXTRACT_SUFX}:mono
EXTRACT_ONLY=	${DISTFILES:C|:[^:]+$||:M*.zip}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sans-serif and monospaced Web Font for small screens

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/${DISTNAME}Fonts${PORTVERSION:S|.||}/License.txt

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2017-02-08

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	WWWDIR_REL="${WWWDIR_REL}"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*.pdf *.rtf

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}
PORTEXAMPLES=	*

MONO_VERSION=	3204

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	UFO source files

DOCS_DISTFILES=	${DISTNAME}_4_1_Version_Report.rtf:sans \
		${DISTNAME}PDF${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
		${DISTNAME}MonoPDF${MONO_VERSION}${EXTRACT_SUFX}:mono
EXAMPLES_DISTFILES=	${DISTNAME}UFO_beta${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
			${DISTNAME}MonoUFO_beta${MONO_VERSION}${EXTRACT_SUFX}:mono

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
.for b in index.html ${PORTNAME:S|$|.css|}
	${INSTALL_DATA} \
		${WRKSRC}/${DISTNAME}Boilerplate${PORTVERSION:S|.||}/${b} \
		${STAGEDIR}${WWWDIR}
.endfor
.for w in eot ttf woff woff2
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${w}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}*Fonts*/WEB/${w:tu}/${DISTNAME}*.${w} \
		${STAGEDIR}${WWWDIR}/${w}/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DISTDIR}/${DISTFILES:C|:[^:]+$||:M*.rtf} ${WRKSRC}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|:M*.rtf} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/${DISTNAME}*PDF*/|:M*.pdf} \
		${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for e in ${EXAMPLES_DISTFILES:R:C|:[^:]+$||}
	(cd ${WRKSRC}/${e} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
. endfor
.endif

.include <bsd.port.mk>

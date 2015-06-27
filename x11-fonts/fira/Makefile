# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	4.102
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.carrois.com/downloads/%SUBDIR%/:sans,mono \
		SF/horia/${CATEGORIES}/${PORTNAME}/%SUBDIR%/:sans,mono
MASTER_SITE_SUBDIR=	${PORTNAME}_4_1/:sans ${PORTNAME}_mono_3_2/:mono
DISTNAME=	${PORTNAME:S|f|F|}
DISTFILES=	${DISTNAME}Fonts${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
		${DISTNAME}MonoFonts${MINOR_VERSION}${EXTRACT_SUFX}:mono
EXTRACT_ONLY=	${DISTFILES:C|:[^:]+$||:M*${EXTRACT_SUFX}}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Sans-serif and monospaced typeface for small screens

BROKEN_FreeBSD_9=	fails to extract

LICENSE=	OFL11

USES=		fonts zip
USE_XORG=	x11
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

PORTDOCS=	*.pdf *.rtf
PORTEXAMPLES=	*

MINOR_VERSION=	3202

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	UFO source files

DOCS_DISTFILES=	${DISTNAME}_4_1_Version_Report.rtf:sans \
		${DISTNAME}PDF${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
		${DISTNAME}MonoPDF${MINOR_VERSION}${EXTRACT_SUFX}:mono
EXAMPLES_DISTFILES=	${DISTNAME}UFO_beta${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
			${DISTNAME}MonoUFO_beta${MINOR_VERSION}${EXTRACT_SUFX}:mono

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}*Fonts*/OTF/*.otf \
		${STAGEDIR}${FONTSDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DISTDIR}/${DISTNAME}_4_1_Version_Report.rtf ${WRKSRC}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|:M*.rtf} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/${DISTNAME}*PDF*/|:M*.pdf} \
		${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for e in ${EXAMPLES_DISTFILES:R:C|:[^:]+$||}
	(cd ${WRKDIR}/${e} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
. endfor
.endif

.include <bsd.port.mk>

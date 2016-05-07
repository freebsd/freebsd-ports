# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	4.106
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.carrois.com/downloads/%SUBDIR%/:sans,mono \
		SF/horia/${CATEGORIES}/${PORTNAME}/%SUBDIR%/:sans,mono
MASTER_SITE_SUBDIR=	${PORTNAME}_4_1/:sans ${PORTNAME}_mono_3_2/:mono
DISTNAME=	${PORTNAME:S|f|F|}
DISTFILES=	${DISTNAME}Fonts${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
		${DISTNAME}MonoFonts${MONO_VERSION}${EXTRACT_SUFX}:mono
EXTRACT_ONLY=	${DISTFILES:C|:[^:]+$||:M*.zip}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Sans-serif and monospaced typeface for small screens

LICENSE=	OFL11

USES=		fonts zip
USE_XORG=	x11
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

PORTDOCS=	*.pdf *.rtf
PORTEXAMPLES=	*

MONO_VERSION=	3206

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	UFO source files

DOCS_DISTFILES=	${DISTNAME}_4_1_Version_Report.rtf:sans \
		${DISTNAME}PDF${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
		${DISTNAME}MonoPDF${MONO_VERSION}${EXTRACT_SUFX}:mono
EXAMPLES_DISTFILES=	${DISTNAME}UFO_beta${PORTVERSION:S|.||}${EXTRACT_SUFX}:sans \
			${DISTNAME}MonoUFO_beta${MONO_VERSION}${EXTRACT_SUFX}:mono

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}*Fonts*/OTF/*.otf \
		${STAGEDIR}${FONTSDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DISTDIR}/${DISTFILES:C|:[^:]+$||:M*.rtf} ${WRKSRC}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|:M*.rtf} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/${DISTNAME}*PDF*/|:M*.pdf} \
		${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${EXAMPLES_DISTFILES:R:C|:[^:]+$||}
	(cd ${WRKSRC}/${e} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>

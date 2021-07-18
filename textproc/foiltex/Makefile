# Created by: Stefan Walter <sw@gegenunendlich.de>

PORTNAME=	foiltex
PORTVERSION=	2.1.4b
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	TEX_CTAN/macros/latex/contrib/${PORTNAME}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of LaTeX files for making foils

# Converted from NO_CDROM
LICENSE=	foiltex
LICENSE_NAME=	foiltex
LICENSE_TEXT=	Redistribution on a not-for-profit basis only
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USE_TEX=	latex
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

LATEX_CMD=	${LOCALBASE}/bin/latex

FOIL_DIR=	share/texmf/tex/latex/${PORTNAME}
FOIL_FILES=	foil17.clo foil20.clo foil25.clo foil30.clo foils.cls \
		foils.sty foilshrt.clo fltfonts.def

PORTDOCS=	foiltex.dtx foiltex.dvi
PORTEXAMPLES=	sampfoil.tex
PLIST_FILES=	${FOIL_FILES:S,^,${FOIL_DIR}/,}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/foiltex.ins ${WRKSRC}/foiltex.ins
	${CP} ${DISTDIR}/foiltex.dtx ${WRKSRC}/foiltex.dtx

do-build:
	@cd ${WRKSRC} && ${LATEX_CMD} foiltex.ins && \
		${LATEX_CMD} foiltex.dtx && \
		${LATEX_CMD} foiltex.dtx && \
		${LATEX_CMD} foiltex.dtx

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${FOIL_DIR}
.for file in ${FOIL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/${FOIL_DIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for file in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

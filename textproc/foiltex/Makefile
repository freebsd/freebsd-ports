# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	foiltex
PORTVERSION=	2.1.4b
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/${PORTNAME}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of LaTeX files for making foils

NO_CDROM=	Redistribution on a not-for-profit basis only

USE_TEX=	latex
NO_WRKSUBDIR=	yes

LATEX_CMD=	${LOCALBASE}/bin/latex

FOIL_DIR=	share/texmf/tex/latex/${PORTNAME}
FOIL_FILES=	foil17.clo foil20.clo foil25.clo foil30.clo foils.cls \
		foils.sty foilshrt.clo fltfonts.def

PORTDOCS=	foiltex.dtx foiltex.dvi
PORTEXAMPLES=	sampfoil.tex
PLIST_FILES=	${FOIL_FILES:S,^,${FOIL_DIR}/,}
PLIST_DIRS=	${FOIL_DIR}

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/foiltex.ins ${WRKDIR}/foiltex.ins
	${CP} ${DISTDIR}/foiltex.dtx ${WRKDIR}/foiltex.dtx

do-build:
	@cd ${WRKDIR} && ${LATEX_CMD} foiltex.ins && \
		${LATEX_CMD} foiltex.dtx && \
		${LATEX_CMD} foiltex.dtx && \
		${LATEX_CMD} foiltex.dtx

do-install:
# install data files
	@${MKDIR} ${PREFIX}/${FOIL_DIR}
.for file in ${FOIL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/${FOIL_DIR}
.endfor
# install docs and example file?
.if !defined(NOPORTDOCS)
# install docs...
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
# ...and examples
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif

post-install:
	${SETENV} LOCALBASE=${LOCALBASE} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

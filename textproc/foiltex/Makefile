# New ports collection makefile for:	foiltex
# Date created:		07 November 2003
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	foiltex
PORTVERSION=	2.1.4a
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	nonfree/macros/latex/contrib/${PORTNAME}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	A collection of LaTeX files for making foils

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_CDROM=	redistribution on a not-for-profit basis only

NO_WRKSUBDIR=	yes

LATEX_CMD=	${LOCALBASE}/bin/latex

FOIL_DIR=	${PREFIX}/share/texmf/tex/latex/${PORTNAME}
DOC_FILES=	${WRKDIR}/foiltex.dtx ${WRKDIR}/foiltex.dvi
EXAMPLE_FILES=	${WRKDIR}/sampfoil.tex
FOIL_FILES=	${WRKDIR}/foil17.clo ${WRKDIR}/foil20.clo \
		${WRKDIR}/foil25.clo ${WRKDIR}/foil30.clo \
		${WRKDIR}/foils.cls ${WRKDIR}/foils.sty \
		${WRKDIR}/foilshrt.clo ${WRKDIR}/fltfonts.def
PLIST_SUB=	FOIL_DIR="${FOIL_DIR:S,^${PREFIX}/,,}"

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
# install docs and example file?
.if !defined(NOPORTDOCS)
# install docs...
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR}
# ...and examples
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLE_FILES} ${EXAMPLESDIR}
.endif
# install data files
	@${MKDIR} ${FOIL_DIR}
	@${INSTALL_DATA} ${FOIL_FILES} ${FOIL_DIR}

post-install:
	${SETENV} LOCALBASE=${LOCALBASE} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

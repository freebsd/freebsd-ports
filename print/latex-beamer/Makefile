# New ports collection makefile for:	latex-beamer
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-beamer
PORTVERSION=	2.21
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX class to create a beamer presentation

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/xcolor/xcolor.sty:${PORTSDIR}/print/latex-xcolor \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/pgf/pgf.sty:${PORTSDIR}/print/latex-pgf \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

NO_BUILD=	YES
PLIST=		${WRKDIR}/pkg-plist

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_SUBDIRS=	art base emulation/examples emulation themes emacs examples \
		lyx/examples lyx/layouts lyx/templates lyx
CLASS_FILES=	art/beamericonarticle.eps art/beamericonarticle.pdf \
		art/beamericonarticle.tex art/beamericonarticle.20.eps \
		art/beamericonarticle.20.pdf art/beamericonbook.eps \
		art/beamericonbook.pdf art/beamericonbook.tex \
		art/beamericonbook.20.pdf art/beamericonbook.20.eps \
		base/beamer.cls base/beamerbasearticle.sty \
		base/beamerbaseboxes.sty base/beamerbasecolor.sty \
		base/beamerbasecompatibility.sty base/beamerbasedecode.sty \
		base/beamerbasefont.sty base/beamerbaseframe.sty \
		base/beamerbaseframecomponents.sty base/beamerbaselocalstructure.sty \
		base/beamerbasemodes.sty base/beamerbasemisc.sty \
		base/beamerbasenotes.sty base/beamerbasenavigation.sty \
		base/beamerbaseoverlay.sty base/beamerbaseoptions.sty \
		base/beamerbasesection.sty base/beamerbasetemplates.sty \
		base/beamerbasetheorems.sty base/beamerbasetitle.sty \
		base/beamerbasetoc.sty \
		emulation/beamerfoils.sty emulation/beamerprosper.sty \
		emulation/beamerseminar.sty emulation/beamertexpower.sty\
		emulation/examples/beamerexample-foils.pdf \
		emulation/examples/beamerexample-foils.tex \
		emulation/examples/beamerexample-prosper.pdf \
		emulation/examples/beamerexample-prosper.tex \
		emulation/examples/beamerexample-seminar.pdf \
		emulation/examples/beamerexample-seminar.tex \
		emulation/examples/beamerexample-texpower.pdf \
		emulation/examples/beamerexample-texpower.tex \
		themes/beamerthemebars.sty themes/beamerthemeboxes.sty \
		themes/beamerthemeclassic.sty themes/beamerthemelined.sty \
		themes/beamerthemeplain.sty themes/beamerthemeshadow.sty \
		themes/beamerthemesidebardark.sty \
		themes/beamerthemesidebardarktab.sty \
		themes/beamerthemesidebar.sty themes/beamerthemesidebartab.sty \
		themes/beamerthemesplit.sty themes/beamerthemetreebars.sty \
		themes/beamerthemetree.sty emacs/beamer.el \
		examples/beamerexample1.pdf examples/beamerexample1.tex \
		examples/beamerexample2.article.pdf \
		examples/beamerexample2.article.tex \
		examples/beamerexample2.beamer.pdf \
		examples/beamerexample2.beamer.tex examples/beamerexample2.tex \
		examples/beamerexample3.pdf examples/beamerexample3.tex \
		examples/beamerexample4.pdf examples/beamerexample4.tex \
		examples/beamerexample5.pdf examples/beamerexample5.tex \
		examples/beamerexample6.pdf examples/beamerexample6.tex \
		examples/beamer-computer.jpg examples/beamer-computerred.jpg \
		examples/beamer-computer-mask.jpg examples/beamer-g4.jpg \
		examples/beamer-g4red.jpg examples/beamer-g4-mask.jpg \
		examples/beamer-ram.jpg examples/beamer-ram-mask.jpg \
		examples/beamer-tu-logo.jpg examples/beamer-ur-logo.jpg \
		examples/beamer-tu-logo-mask.jpg examples/beamer-ur-logo-mask.jpg \
		lyx/examples/beamerlyxexample1.lyx \
		lyx/examples/beamerlyxexample1.pdf \
		lyx/examples/beamer-icsi-logo.pdf \
		lyx/examples/beamer-knight1.png \
		lyx/examples/beamer-knight1-mask.png \
		lyx/examples/beamer-knight2.png \
		lyx/examples/beamer-knight2-mask.png \
		lyx/examples/beamer-knight3.png \
		lyx/examples/beamer-knight3-mask.png \
		lyx/examples/beamer-knight4.png \
		lyx/examples/beamer-knight4-mask.png \
		lyx/layouts/beamer.layout \
		lyx/templates/beamerpresentation.lyx

DOC_FILES+=	AUTHORS ChangeLog FILES INSTALL README TODO \
		doc/beameruserguide.pdf doc/beameruserguide.tex \
		doc/themebars.pdf doc/themebars2.pdf \
		doc/themeboxes.pdf doc/themeboxes2.pdf \
		doc/themeclassic.pdf doc/themeclassic2.pdf \
		doc/themelined.pdf doc/themelined2.pdf \
		doc/themeplain.pdf doc/themeplain2.pdf \
		doc/themeshadow.pdf doc/themeshadow2.pdf \
		doc/themesidebar.pdf doc/themesidebar2.pdf \
		doc/themesidebardark.pdf doc/themesidebardark2.pdf \
		doc/themesidebardarktab.pdf doc/themesidebardarktab2.pdf \
		doc/themesidebartab.pdf doc/themesidebartab2.pdf \
		doc/themesplit.pdf doc/themesplit2.pdf \
		doc/themesplitcondensed.pdf doc/themesplitcondensed2.pdf \
		doc/themetree.pdf doc/themetree2.pdf \
		doc/themetreebars.pdf doc/themetreebars2.pdf

pre-install:
	${RM} -f ${PLIST}
	${TOUCH} ${PLIST}
.if !defined(NOPORTDOCS)
	(for file in ${DOC_FILES}; do \
		${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${file}"; \
		done; \
		${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}/doc"; \
		${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}";) >> ${PLIST}
.endif
	(for file in ${CLASS_FILES}; do \
		${ECHO_CMD} "${CLASSDIR}/$${file}"; \
		done; \
		for D in ${CLASS_SUBDIRS:S,^,/,g} "" ; do \
			${ECHO_CMD} "@dirrm ${CLASSDIR}$${D}"; \
		done; \
		${ECHO_CMD} '@exec ${MKTEXLSR}'; \
		${ECHO_CMD} '@unexec ${MKTEXLSR}' ) >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
.for D in ${CLASS_SUBDIRS}
	${MKDIR} ${PREFIX}/${CLASSDIR}/${D}
.if ${CLASS_FILES:M${D}/*:N${D}/*/*} != ""
	${INSTALL_DATA} ${CLASS_FILES:M${D}/*:N${D}/*/*:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}/${D}
.endif
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:Ndoc/*:S@^@${WRKSRC}/@} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${DOC_FILES:Mdoc/*:S@^@${WRKSRC}/@} ${DOCSDIR}/doc
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>

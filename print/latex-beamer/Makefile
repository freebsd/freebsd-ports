# New ports collection makefile for:	latex-beamer
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-beamer
PORTVERSION=	2.01
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX class to create a beamer presentation

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/xcolor/xcolor.sty:${PORTSDIR}/print/latex-xcolor \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/pgf/pgf.sty:${PORTSDIR}/print/latex-pgf \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

NO_BUILD=	YES
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	art/beamericonarticle.eps
CLASS_FILES+=	art/beamericonarticle.pdf
CLASS_FILES+=	art/beamericonarticle.tex
CLASS_FILES+=	art/beamericonarticle.20.eps
CLASS_FILES+=	art/beamericonarticle.20.pdf
CLASS_FILES+=	art/beamericonbook.eps
CLASS_FILES+=	art/beamericonbook.pdf
CLASS_FILES+=	art/beamericonbook.tex
CLASS_FILES+=	art/beamericonbook.20.pdf
CLASS_FILES+=	art/beamericonbook.20.eps
CLASS_FILES+=	base/beamer.cls
CLASS_FILES+=	base/beamerbasearticle.sty
CLASS_FILES+=	base/beamerbaseboxes.sty
CLASS_FILES+=	base/beamerbasecolor.sty
CLASS_FILES+=	base/beamerbasecompatibility.sty
CLASS_FILES+=	base/beamerbasedecode.sty
CLASS_FILES+=	base/beamerbasefont.sty
CLASS_FILES+=	base/beamerbaseframe.sty
CLASS_FILES+=	base/beamerbaseframecomponents.sty
CLASS_FILES+=	base/beamerbaselocalstructure.sty
CLASS_FILES+=	base/beamerbasemodes.sty
CLASS_FILES+=	base/beamerbasemisc.sty
CLASS_FILES+=	base/beamerbasenotes.sty
CLASS_FILES+=	base/beamerbasenavigation.sty
CLASS_FILES+=	base/beamerbaseoverlay.sty
CLASS_FILES+=	base/beamerbaseoptions.sty
CLASS_FILES+=	base/beamerbasesection.sty
CLASS_FILES+=	base/beamerbasetemplates.sty
CLASS_FILES+=	base/beamerbasetitle.sty
CLASS_FILES+=	base/beamerbasetoc.sty
CLASS_FILES+=	themes/beamerthemebars.sty
CLASS_FILES+=	themes/beamerthemeboxes.sty
CLASS_FILES+=	themes/beamerthemeclassic.sty
CLASS_FILES+=	themes/beamerthemelined.sty
CLASS_FILES+=	themes/beamerthemeplain.sty
CLASS_FILES+=	themes/beamerthemeshadow.sty
CLASS_FILES+=	themes/beamerthemesidebardark.sty
CLASS_FILES+=	themes/beamerthemesidebardarktab.sty
CLASS_FILES+=	themes/beamerthemesidebar.sty
CLASS_FILES+=	themes/beamerthemesidebartab.sty
CLASS_FILES+=	themes/beamerthemesplit.sty
CLASS_FILES+=	themes/beamerthemetreebars.sty
CLASS_FILES+=	themes/beamerthemetree.sty
CLASS_FILES+=	examples/beamerexample1.pdf
CLASS_FILES+=	examples/beamerexample1.tex
CLASS_FILES+=	examples/beamerexample2.article.pdf
CLASS_FILES+=	examples/beamerexample2.article.tex
CLASS_FILES+=	examples/beamerexample2.beamer.pdf
CLASS_FILES+=	examples/beamerexample2.beamer.tex
CLASS_FILES+=	examples/beamerexample3.pdf
CLASS_FILES+=	examples/beamerexample3.tex
CLASS_FILES+=	examples/beamerexample4.pdf
CLASS_FILES+=	examples/beamerexample4.tex
CLASS_FILES+=	examples/beamerexample5.pdf
CLASS_FILES+=	examples/beamerexample5.tex
CLASS_FILES+=	examples/beamerexample6.pdf
CLASS_FILES+=	examples/beamerexample6.tex
CLASS_FILES+=	examples/beamer-computer.jpg
CLASS_FILES+=	examples/beamer-computerred.jpg
CLASS_FILES+=	examples/beamer-computer-mask.jpg
CLASS_FILES+=	examples/beamer-g4.jpg
CLASS_FILES+=	examples/beamer-g4red.jpg
CLASS_FILES+=	examples/beamer-g4-mask.jpg
CLASS_FILES+=	examples/beamer-ram.jpg
CLASS_FILES+=	examples/beamer-ram-mask.jpg
CLASS_FILES+=	examples/beamer-tu-logo.jpg
CLASS_FILES+=	examples/beamer-ur-logo.jpg
CLASS_FILES+=	examples/beamer-tu-logo-mask.jpg
CLASS_FILES+=	examples/beamer-ur-logo-mask.jpg
CLASS_FILES+=	lyx/examples/beamerlyxexample1.lyx
CLASS_FILES+=	lyx/examples/beamerlyxexample1.pdf
CLASS_FILES+=	lyx/examples/beamer-icsi-logo.pdf
CLASS_FILES+=	lyx/examples/beamer-knight1.png
CLASS_FILES+=	lyx/examples/beamer-knight1-mask.png
CLASS_FILES+=	lyx/examples/beamer-knight2.png
CLASS_FILES+=	lyx/examples/beamer-knight2-mask.png
CLASS_FILES+=	lyx/examples/beamer-knight3.png
CLASS_FILES+=	lyx/examples/beamer-knight3-mask.png
CLASS_FILES+=	lyx/examples/beamer-knight4.png
CLASS_FILES+=	lyx/examples/beamer-knight4-mask.png
CLASS_FILES+=	lyx/layouts/beamer.layout
CLASS_FILES+=	lyx/templates/beamerpresentation.lyx

DOC_FILES+=	AUTHORS ChangeLog FILES INSTALL
DOC_FILES+=	README TODO
DOC_FILES+=	doc/beameruserguide.pdf
DOC_FILES+=	doc/beameruserguide.tex
DOC_FILES+=	doc/themebars.pdf
DOC_FILES+=	doc/themebars2.pdf
DOC_FILES+=	doc/themeboxes.pdf
DOC_FILES+=	doc/themeboxes2.pdf
DOC_FILES+=	doc/themeclassic.pdf
DOC_FILES+=	doc/themeclassic2.pdf
DOC_FILES+=	doc/themelined.pdf
DOC_FILES+=	doc/themelined2.pdf
DOC_FILES+=	doc/themeplain.pdf
DOC_FILES+=	doc/themeplain2.pdf
DOC_FILES+=	doc/themeshadow.pdf
DOC_FILES+=	doc/themeshadow2.pdf
DOC_FILES+=	doc/themesidebar.pdf
DOC_FILES+=	doc/themesidebar2.pdf
DOC_FILES+=	doc/themesidebardark.pdf
DOC_FILES+=	doc/themesidebardark2.pdf
DOC_FILES+=	doc/themesidebardarktab.pdf
DOC_FILES+=	doc/themesidebardarktab2.pdf
DOC_FILES+=	doc/themesidebartab.pdf
DOC_FILES+=	doc/themesidebartab2.pdf
DOC_FILES+=	doc/themesplit.pdf
DOC_FILES+=	doc/themesplit2.pdf
DOC_FILES+=	doc/themesplitcondensed.pdf
DOC_FILES+=	doc/themesplitcondensed2.pdf
DOC_FILES+=	doc/themetree.pdf
DOC_FILES+=	doc/themetree2.pdf
DOC_FILES+=	doc/themetreebars.pdf
DOC_FILES+=	doc/themetreebars2.pdf

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
.for D in art base themes examples lyx/examples lyx/layouts lyx/templates
	${MKDIR} ${PREFIX}/${CLASSDIR}/${D}
	${INSTALL_DATA} ${CLASS_FILES:M${D}/*:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}/${D}
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

# New ports collection makefile for:	latex-auto-greek
# Date created:				13 March 2005
# Whom:					EelVex
#
# $FreeBSD$

PORTNAME=	latex-auto-greek
PORTVERSION=	1.0b
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://a.physics.upatras.gr/~mplekos/files/

MAINTAINER=	mplekos@physics.upatras.gr
COMMENT=	A LaTeX package for switching between greek/latintext automaticaly

BUILD_DEPENDS=	updmap-sys:${PORTSDIR}/print/teTeX-base \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		fmtutil-sys:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_BUILD=	YES
PLIST_SUB=	TEXMFDIST=${TEXMFDIST} UPDMAP=${UPDMAP} \
		CLASSDIR=${CLASSDIR} FMTUTIL=${FMTUTIL} \
		MKTEXLSR=${MKTEXLSR} AFFONTDIR=${AFFONTDIR} \
		PFFONTDIR=${PFFONTDIR} TFFONTDIR=${TFFONTDIR} \
		ENCDIR=${ENCDIR} PSMAPDIR=${PSMAPDIR} \
		UPDMAP_FILE=${UPDMAP_FILE} HYPHDIR=${HYPHDIR}

TEXMFDIST=	share/texmf-dist
TEXMFCONFIG=	share/texmf-config
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
UPDMAP=		${LOCALBASE}/bin/updmap-sys
FMTUTIL=	${LOCALBASE}/bin/fmtutil-sys
CLASSDIR=	${TEXMFDIST}/tex/latex/${PORTNAME:S/^latex-//}
FONTDIR=	${TEXMFDIST}/fonts
TRFONTDIR=	${FONTDIR}/truetype/public/${PORTNAME:S/^latex-//}
PFFONTDIR=	${FONTDIR}/type1/public/${PORTNAME:S/^latex-//}
AFFONTDIR=	${FONTDIR}/afm/public/${PORTNAME:S/^latex-//}
TFFONTDIR=	${FONTDIR}/tfm/public/${PORTNAME:S/^latex-//}
PSMAPDIR=	${FONTDIR}/map/dvips/${PORTNAME:S/^latex-//}
ENCDIR=		${FONTDIR}/enc/dvips/${PORTNAME:S/^latex-//}
HYPHDIR=	${TEXMFDIST}/tex/generic/hyphen/
WRKSRC=		${WRKDIR}/

DOC_FILES=	README ag-test.tex ag-test.dvi

UPDMAP_FILE=	${TEXMFCONFIG}/web2c/updmap.cfg
CLASS_FILES=	auto-greek.sty updmap.inc ot1grcouri.fd ot1grarial.fd ot1grtimes.fd grushyph.tex
PFFONT_FILES=	*.pfb
AFFONT_FILES=	*.afm
TFFONT_FILES=	*.tfm
PSMAP_FILES=	greek.map
ENC_FILES=	greek.enc
HYPH_FILES=	grushyph.tex
MAP_INC=	updmap.inc

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${MKDIR} ${PREFIX}/${PFFONTDIR}
	${MKDIR} ${PREFIX}/${AFFONTDIR}
	${MKDIR} ${PREFIX}/${TFFONTDIR}
	${MKDIR} ${PREFIX}/${PSMAPDIR}
	${MKDIR} ${PREFIX}/${ENCDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${PFFONT_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${PFFONTDIR}
	${INSTALL_DATA} ${AFFONT_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${AFFONTDIR}
	${INSTALL_DATA} ${TFFONT_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${TFFONTDIR}
	${INSTALL_DATA} ${PSMAP_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${PSMAPDIR}
	${INSTALL_DATA} ${ENC_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${ENCDIR}
	${CAT} ${MAP_INC:S@^@${WRKSRC}/@} >> ${PREFIX}/${UPDMAP_FILE}
	${CP} ${PREFIX}/${HYPHDIR}/hyphen.tex ${PREFIX}/${HYPHDIR}/hyphen.tex.old
	${INSTALL_DATA} ${HYPH_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${HYPHDIR}/hyphen.tex
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}
	${UPDMAP}
	${FMTUTIL} --byfmt latex
	${FMTUTIL} --byfmt pdflatex

.include <bsd.port.mk>

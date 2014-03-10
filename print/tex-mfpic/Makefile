# Created by: hrs
# $FreeBSD$

PORTNAME=	mfpic
PORTVERSION=	1.06.20110308
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://comp.uark.edu/~luecking/tex/
PKGNAMEPREFIX=	tex-
DISTNAME=	${PORTNAME}106
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A TeX package that supports drawing pictures

USES=		zip
USE_TEX=	latex
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		TEXMFDIR=${TEXMFDIR}
TEXMFDIR=	share/texmf
TEXMF_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/etex
YES_CMD=	/usr/bin/yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	${CLASS_FILES:S,^,${CLASSDIR}/,} \
		${MP_FILES:S,^,${MPDIR}/,} \
		${MF_FILES:S,^,${MFDIR}/,} \
		${DOC_FILES:S,^doc/,,:S,^,${DDIR}/,}

CLASSDIR=	${TEXMFDIR}/tex/generic/${PORTNAME}
MPDIR=		${TEXMFDIR}/metapost/${PORTNAME}
MFDIR=		${TEXMFDIR}/metafont/${PORTNAME}
DDIR=		${TEXMFDIR}/doc/generic/${PORTNAME}

CLASS_FILES=	mfpic.sty mfpic.tex dvipsnam.mp grafbase.mp
MP_FILES=	dvipsnam.mp grafbase.mp
MF_FILES=	grafbase.mf
DOC_FILES=	README changes.txt install.txt doc/coil.mps \
		doc/lcheadings.ist doc/mfpcard.pdf doc/mfpcard.tex \
		doc/mfpdoc.sty doc/mfpguide.pdf doc/mfpguide.tex \
		doc/mfpic-doc.pdf doc/mfpic-doc.tex

NO_STAGE=	yes
do-build:
	cd ${WRKDIR} && ${YES_CMD} | ${TEX_BIN} mfpic.ins

do-install:
	cd ${WRKDIR} && \
		${INSTALL_DATA} ${CLASS_FILES} ${PREFIX}/${CLASSDIR} && \
		${INSTALL_DATA} ${MP_FILES} ${PREFIX}/${MPDIR} && \
		${INSTALL_DATA} ${MF_FILES} ${PREFIX}/${MFDIR} && \
		${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/${DDIR}

post-install:
	@${MKTEXLSR} ${LOCALBASE}/${TEXMFDIR}

.include <bsd.port.mk>

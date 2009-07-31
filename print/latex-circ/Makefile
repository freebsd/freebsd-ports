# New ports collection makefile for:	latex-circ
# Date created:		2005-07-20
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	circ
PORTVERSION=	1.0f
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://cam.ctan.org/tex-archive/macros/generic/diagrams/ \
		http://theory.uwinnipeg.ca/scripts/CTAN/macros/generic/diagrams/
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A LaTeX package for typesetting circuit diagrams

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

USE_ZIP=	yes

# We need to install in the global texmf-local directory
PREFIX=		${LOCALBASE}
TEXMFLOCAL=	${LOCALBASE}/share/texmf-local
TEXMFLOCAL_DOC=	${TEXMFLOCAL}/doc
TEXMFLOCAL_LSR=	${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_CMD=	${LOCALBASE}/bin/latex

PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

CIRC_INS=	circ.ins
CIRC_DRV=	circ.drv
CIRC_DOC=	circ.dvi circ.pdf

FIND_CLASS=	-type f \( -name "*.sty" -or -name "*.def" \)
FIND_FONTS_PK=	-type f -name "*.*pk"
FIND_FONTS_MF=	-type f -name "*.mf"
FIND_FONTS_TFM=	-type f -name "*.tfm"
CLASS_DIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME}
FONTS_PK_DIR=	${TEXMFLOCAL}/fonts/pk/${PORTNAME}
FONTS_MF_DIR=	${TEXMFLOCAL}/fonts/source/${PORTNAME}
FONTS_TFM_DIR=	${TEXMFLOCAL}/fonts/tfm/${PORTNAME}

.include <bsd.port.pre.mk>

do-build:
	@cd ${WRKSRC}; \
	${TEX_CMD} ${CIRC_INS};

do-install:
	@cd ${WRKSRC}; \
	${MKDIR} ${CLASS_DIR};  \
	CLASSES=$$(${FIND} . ${FIND_CLASS} ); \
	for CLASS in $${CLASSES}; do \
		${INSTALL_DATA} $${CLASS} ${CLASS_DIR}/$${CLASS}; \
	done; \
	${TEX_CMD} ${CIRC_DRV} && ${TEX_CMD} ${CIRC_DRV} && ${TEX_CMD} ${CIRC_DRV}; \
	${MKDIR} ${FONTS_PK_DIR} ${FONTS_MF_DIR} ${FONTS_TFM_DIR}; \
	FONTS_PK=$$(${FIND} . ${FIND_FONTS_PK} ); \
	for PK in $${FONTS_PK}; do \
		${INSTALL_DATA} $${PK} ${FONTS_PK_DIR}/$${PK}; \
	done; \
	FONTS_MF=$$(${FIND} . ${FIND_FONTS_MF} ); \
	for MF in $${FONTS_MF}; do \
		${INSTALL_DATA} $${MF} ${FONTS_MF_DIR}/$${MF}; \
	done; \
	FONTS_TFM=$$(${FIND} . ${FIND_FONTS_TFM} ); \
	for TFM in $${FONTS_TFM}; do \
		${INSTALL_DATA} $${TFM} ${FONTS_TFM_DIR}/$${TFM}; \
	done;
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}; \
	${MKDIR} ${TEXMFLOCAL_DOC}/${PORTNAME}; \
	for doc in ${CIRC_DOC}; do \
	    ${INSTALL_DATA} $${doc} ${TEXMFLOCAL_DOC}/${PORTNAME}/$${doc}; \
	done
.endif

post-install:
	@${MKTEXLSR}

.include <bsd.port.post.mk>

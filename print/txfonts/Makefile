# New ports collection makefile for:	txfonts
# Date created:		2 October 2001
# Whom:			MORI Koji
#
# $FreeBSD$
#

PORTNAME=	txfonts
PORTVERSION=	3.1.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	fonts/txfonts
DISTFILES=	\
	${FONTS_AFM:S%^%afm/%} \
	${FONTS_TFM:S%^%tfm/%} \
	${FONTS_VF:S%^%vf/%} \
	${FONTS_TYPE1:S%^%pfb/%} \
	${DVIPDFM:S%^%dvipdfm/%} \
	${DVIPS:S%^%dvips/%} \
	${LATEX:S%^%input/%}
DISTFILES+=	tx_patch1.zip
EXTRACT_ONLY=	tx_patch1.zip

MAINTAINER=	mori@tri.asanuma.co.jp

DIST_SUBDIR=	txfonts
USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	-d ${TXPATCHDIR}
NO_BUILD=	yes

TEXFONTSDIR=	${PREFIX}/share/texmf/fonts
LATEXMACRODIR=	${PREFIX}/share/texmf/tex/latex
DVIPSCONFDIR=	${PREFIX}/share/texmf/dvips/config

TXDIST=		${DISTDIR}/${DIST_SUBDIR}
TXPATCHDIR=	${WRKDIR}/tx_patch1

DVIPDFM=	txr3.map

DVIPS=	tx8r.enc \
	txr.map \
	txr1.map \
	txr2.map

LATEX=	ly1txr.fd \
	ly1txss.fd \
	ly1txtt.fd \
	omltxmi.fd \
	omltxr.fd \
	omstxr.fd \
	omstxsy.fd \
	omxtxex.fd \
	ot1txr.fd \
	ot1txss.fd \
	ot1txtt.fd \
	t1txr.fd \
	t1txss.fd \
	t1txtt.fd \
	ts1txr.fd \
	ts1txss.fd \
	ts1txtt.fd \
	txfonts.sty \
	utxexa.fd \
	utxmia.fd \
	utxr.fd \
	utxss.fd \
	utxsya.fd \
	utxsyb.fd \
	utxsyc.fd \
	utxtt.fd

FONTS_TYPE1=	\
	rtcxb.pfb \
	rtcxbi.pfb \
	rtcxbss.pfb \
	rtcxi.pfb \
	rtcxr.pfb \
	rtcxss.pfb \
	rtxb.pfb \
	rtxbi.pfb \
	rtxbmi.pfb \
	rtxbsc.pfb \
	rtxbss.pfb \
	rtxbsssc.pfb \
	rtxi.pfb \
	rtxmi.pfb \
	rtxr.pfb \
	rtxsc.pfb \
	rtxss.pfb \
	rtxsssc.pfb \
	t1xbtt.pfb \
	t1xbttsc.pfb \
	t1xtt.pfb \
	t1xttsc.pfb \
	tcxbtt.pfb \
	tcxtt.pfb \
	txbex.pfb \
	txbexa.pfb \
	txbmia.pfb \
	txbsy.pfb \
	txbsya.pfb \
	txbsyb.pfb \
	txbsyc.pfb \
	txbtt.pfb \
	txbttsc.pfb \
	txex.pfb \
	txexa.pfb \
	txmia.pfb \
	txsy.pfb \
	txsya.pfb \
	txsyb.pfb \
	txsyc.pfb \
	txtt.pfb \
	txttsc.pfb

FONTS_AFM=	\
	rtcxb.afm \
	rtcxbi.afm \
	rtcxbss.afm \
	rtcxi.afm \
	rtcxr.afm \
	rtcxss.afm \
	rtxb.afm \
	rtxbi.afm \
	rtxbmi.afm \
	rtxbsc.afm \
	rtxbss.afm \
	rtxbsssc.afm \
	rtxi.afm \
	rtxmi.afm \
	rtxr.afm \
	rtxsc.afm \
	rtxss.afm \
	rtxsssc.afm \
	t1xbtt.afm \
	t1xbttsc.afm \
	t1xtt.afm \
	t1xttsc.afm \
	tcxbtt.afm \
	tcxtt.afm \
	txbex.afm \
	txbexa.afm \
	txbmia.afm \
	txbsy.afm \
	txbsya.afm \
	txbsyb.afm \
	txbsyc.afm \
	txbtt.afm \
	txbttsc.afm \
	txex.afm \
	txexa.afm \
	txmia.afm \
	txsy.afm \
	txsya.afm \
	txsyb.afm \
	txsyc.afm \
	txtt.afm \
	txttsc.afm

FONTS_TFM=	\
	rtcxb.tfm \
	rtcxbi.tfm \
	rtcxbsl.tfm \
	rtcxbss.tfm \
	rtcxbsso.tfm \
	rtcxi.tfm \
	rtcxr.tfm \
	rtcxsl.tfm \
	rtcxss.tfm \
	rtcxsssl.tfm \
	rtxb.tfm \
	rtxbi.tfm \
	rtxbmi.tfm \
	rtxbsc.tfm \
	rtxbsl.tfm \
	rtxbss.tfm \
	rtxbsssc.tfm \
	rtxbsssl.tfm \
	rtxi.tfm \
	rtxmi.tfm \
	rtxphvb.tfm \
	rtxphvbo.tfm \
	rtxphvr.tfm \
	rtxphvro.tfm \
	rtxptmb.tfm \
	rtxptmbi.tfm \
	rtxptmbo.tfm \
	rtxptmr.tfm \
	rtxptmri.tfm \
	rtxptmro.tfm \
	rtxr.tfm \
	rtxsc.tfm \
	rtxsl.tfm \
	rtxss.tfm \
	rtxsssc.tfm \
	rtxsssl.tfm \
	t1xb.tfm \
	t1xbi.tfm \
	t1xbsc.tfm \
	t1xbsl.tfm \
	t1xbss.tfm \
	t1xbsssc.tfm \
	t1xbsssl.tfm \
	t1xbtt.tfm \
	t1xbttsc.tfm \
	t1xbttsl.tfm \
	t1xi.tfm \
	t1xr.tfm \
	t1xsc.tfm \
	t1xsl.tfm \
	t1xss.tfm \
	t1xsssc.tfm \
	t1xsssl.tfm \
	t1xtt.tfm \
	t1xttsc.tfm \
	t1xttsl.tfm \
	tcxb.tfm \
	tcxbi.tfm \
	tcxbsl.tfm \
	tcxbss.tfm \
	tcxbsssl.tfm \
	tcxbtt.tfm \
	tcxbttsl.tfm \
	tcxi.tfm \
	tcxr.tfm \
	tcxsl.tfm \
	tcxss.tfm \
	tcxsssl.tfm \
	tcxtt.tfm \
	tcxttsl.tfm \
	txb.tfm \
	txbex.tfm \
	txbexa.tfm \
	txbi.tfm \
	txbmi.tfm \
	txbmi1.tfm \
	txbmia.tfm \
	txbsc.tfm \
	txbsl.tfm \
	txbss.tfm \
	txbsssc.tfm \
	txbsssl.tfm \
	txbsy.tfm \
	txbsya.tfm \
	txbsyb.tfm \
	txbsyc.tfm \
	txbtt.tfm \
	txbttsc.tfm \
	txbttsl.tfm \
	txex.tfm \
	txexa.tfm \
	txi.tfm \
	txmi.tfm \
	txmi1.tfm \
	txmia.tfm \
	txr.tfm \
	txsc.tfm \
	txsl.tfm \
	txss.tfm \
	txsssc.tfm \
	txsssl.tfm \
	txsy.tfm \
	txsya.tfm \
	txsyb.tfm \
	txsyc.tfm \
	txtt.tfm \
	txttsc.tfm \
	txttsl.tfm \
	tyxb.tfm \
	tyxbi.tfm \
	tyxbsc.tfm \
	tyxbsl.tfm \
	tyxbss.tfm \
	tyxbsssc.tfm \
	tyxbsssl.tfm \
	tyxbtt.tfm \
	tyxbttsc.tfm \
	tyxbttsl.tfm \
	tyxi.tfm \
	tyxr.tfm \
	tyxsc.tfm \
	tyxsl.tfm \
	tyxss.tfm \
	tyxsssc.tfm \
	tyxsssl.tfm \
	tyxtt.tfm \
	tyxttsc.tfm \
	tyxttsl.tfm

FONTS_VF=	\
	t1xb.vf \
	t1xbi.vf \
	t1xbsc.vf \
	t1xbsl.vf \
	t1xbss.vf \
	t1xbsssc.vf \
	t1xbsssl.vf \
	t1xi.vf \
	t1xr.vf \
	t1xsc.vf \
	t1xsl.vf \
	t1xss.vf \
	t1xsssc.vf \
	t1xsssl.vf \
	tcxb.vf \
	tcxbi.vf \
	tcxbsl.vf \
	tcxbss.vf \
	tcxbsssl.vf \
	tcxi.vf \
	tcxr.vf \
	tcxsl.vf \
	tcxss.vf \
	tcxsssl.vf \
	txb.vf \
	txbi.vf \
	txbmi.vf \
	txbmi1.vf \
	txbsc.vf \
	txbsl.vf \
	txbss.vf \
	txbsssc.vf \
	txbsssl.vf \
	txi.vf \
	txmi.vf \
	txmi1.vf \
	txr.vf \
	txsc.vf \
	txsl.vf \
	txss.vf \
	txsssc.vf \
	txsssl.vf \
	tyxb.vf \
	tyxbi.vf \
	tyxbsc.vf \
	tyxbsl.vf \
	tyxbss.vf \
	tyxbsssc.vf \
	tyxbsssl.vf \
	tyxbtt.vf \
	tyxbttsc.vf \
	tyxbttsl.vf \
	tyxi.vf \
	tyxr.vf \
	tyxsc.vf \
	tyxsl.vf \
	tyxss.vf \
	tyxsssc.vf \
	tyxsssl.vf \
	tyxtt.vf \
	tyxttsc.vf \
	tyxttsl.vf

do-install:
	@if [ ! -d ${TEXFONTSDIR}/afm/txr ]; then \
	  ${MKDIR} ${TEXFONTSDIR}/afm/txr; fi
	@(for i in ${FONTS_AFM}; do \
	  ${INSTALL_DATA} ${TXDIST}/afm/$$i ${TEXFONTSDIR}/afm/txr/ ; done)
	@if [ ! -d ${TEXFONTSDIR}/tfm/txr ]; then \
	  ${MKDIR} ${TEXFONTSDIR}/tfm/txr; fi
	@(for i in ${FONTS_TFM}; do \
	  ${INSTALL_DATA} ${TXDIST}/tfm/$$i ${TEXFONTSDIR}/tfm/txr/ ; done)
	@if [ ! -d ${TEXFONTSDIR}/vf/txr ]; then \
	  ${MKDIR} ${TEXFONTSDIR}/vf/txr; fi
	@(for i in ${FONTS_VF}; do \
	  ${INSTALL_DATA} ${TXDIST}/vf/$$i ${TEXFONTSDIR}/vf/txr/ ; done)
	@if [ ! -d ${TEXFONTSDIR}/type1/txr ]; then \
	  ${MKDIR} ${TEXFONTSDIR}/type1/txr; fi
	@(for i in ${FONTS_TYPE1}; do \
	  ${INSTALL_DATA} ${TXDIST}/pfb/$$i ${TEXFONTSDIR}/type1/txr/ ; done)
	@if [ ! -d ${LATEXMACRODIR}/txr ]; then \
	  ${MKDIR} ${LATEXMACRODIR}/txr; fi
	@(for i in ${LATEX}; do \
	  ${INSTALL_DATA} ${TXDIST}/input/$$i ${LATEXMACRODIR}/txr/ ; done)
	@if [ ! -d ${DVIPSCONFDIR} ]; then \
	  ${MKDIR} ${DVIPSCONFDIR}; fi
	@(for i in ${DVIPS}; do \
	  ${INSTALL_DATA} ${TXDIST}/dvips/$$i ${DVIPSCONFDIR}/ ; done)
	@(for i in ${TXPATCH_NAME}; do \
	  ${INSTALL_DATA} ${TXPATCHDIR}/$$i.tfm ${TEXFONTSDIR}/tfm/txr/ ; done)
	@(for i in ${TXPATCH_NAME}; do \
	  ${INSTALL_DATA} ${TXPATCHDIR}/$$i.vf ${TEXFONTSDIR}/vf/txr/ ; done)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${TXPATCHDIR}/doc/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

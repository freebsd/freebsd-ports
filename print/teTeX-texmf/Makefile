# New ports collection makefile for:	teTeX-texmf
# Date created:		5 June 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX-texmf
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:1
MASTER_SITE_SUBDIR=	systems/unix/teTeX/3.0/distrib
DISTFILES=	${TETEX_TEXMF_SRC} dvipsk-jpatch-p1.6a1${EXTRACT_SUFX}:1
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	dvipsk-jpatch-p1.6a1${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Thomas Esser's distribution of TeX & friends (texmf tree)

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/share/fonts/cmpsfont/README:${PORTSDIR}/print/cmpsfont \
		${LOCALBASE}/share/fonts/amspsfont/READ.ME:${PORTSDIR}/print/amspsfnt
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/share/fonts/cmpsfont/README:${PORTSDIR}/print/cmpsfont \
		${LOCALBASE}/share/fonts/amspsfont/READ.ME:${PORTSDIR}/print/amspsfnt

CONFLICTS=	latex2e-[0-9]* tex-[0-9]* dvips-[0-9]* xdvi-[0-9]*

.include <bsd.port.pre.mk>

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} \
		TEXMFDISTDIR=${TEXMFDISTDIR} \
		TEXMFCONFIGDIR=${TEXMFCONFIGDIR} \
		MKTEXLSR=${MKTEXLSR} \
		TEXMF_LSR=${TEXMF_LSR}
CONFLICTS=	ja-ptex-base-[0-9]*

TETEX_TEXMF_SRC=tetex-texmf-${PORTVERSION}.tar.gz
TEXMFDIR=	share/texmf
TEXMF_LSR=	${PREFIX}/${TEXMFDIR}/ls-R
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
TEXMFVARDIR=	share/texmf-var
TEXMFVAR_LSR=	${LOCALBASE}/${TEXMFVARDIR}/ls-R
TEXMFDISTDIR=	share/texmf-dist
TEXMFDIST_LSR=	${LOCALBASE}/${TEXMFDISTDIR}/ls-R
TEXMFCONFIGDIR=	share/texmf-config
TEXMFCONFIG_LSR=${LOCALBASE}/${TEXMFCONFIGDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

EXCLUDE_LIST=	fonts/type1/bluesky/cm/\* \
		fonts/type1/bluesky/cmextra/\* \
		fonts/type1/bluesky/euler/\* \
		fonts/type1/bluesky/latex/\* \
		fonts/type1/bluesky/symbols/\* \
		fonts/type1/bluesky/cyrillic/\*

CMPSFONTDIR=	${LOCALBASE}/share/fonts/cmpsfont
AMSPSFONTDIR=	${LOCALBASE}/share/fonts/amspsfont

CMFONTS=	cmb10.pfb cmbsy10.pfb cmbx10.pfb cmbx12.pfb cmbx5.pfb \
		cmbx6.pfb cmbx7.pfb cmbx8.pfb cmbx9.pfb cmbxsl10.pfb \
		cmbxti10.pfb cmcsc10.pfb cmdunh10.pfb cmex10.pfb cmff10.pfb \
		cmfi10.pfb cmfib8.pfb cminch.pfb cmitt10.pfb cmmi10.pfb \
		cmmi12.pfb cmmi5.pfb cmmi6.pfb cmmi7.pfb cmmi8.pfb cmmi9.pfb \
		cmmib10.pfb cmr10.pfb cmr12.pfb cmr17.pfb cmr5.pfb cmr6.pfb \
		cmr7.pfb cmr8.pfb cmr9.pfb cmsl10.pfb cmsl12.pfb cmsl8.pfb \
		cmsl9.pfb cmsltt10.pfb cmss10.pfb cmss12.pfb cmss17.pfb \
		cmss8.pfb cmss9.pfb cmssbx10.pfb cmssdc10.pfb cmssi10.pfb \
		cmssi12.pfb cmssi17.pfb cmssi8.pfb cmssi9.pfb cmssq8.pfb \
		cmssqi8.pfb cmsy10.pfb cmsy5.pfb cmsy6.pfb cmsy7.pfb \
		cmsy8.pfb cmsy9.pfb cmtcsc10.pfb cmtex10.pfb cmtex8.pfb \
		cmtex9.pfb cmti10.pfb cmti12.pfb cmti7.pfb cmti8.pfb \
		cmti9.pfb cmtt10.pfb cmtt12.pfb cmtt8.pfb cmtt9.pfb \
		cmu10.pfb cmvtt10.pfb
LATEXFONTS=	lasy10.pfb lasy5.pfb lasy6.pfb lasy7.pfb lasy8.pfb lasy9.pfb \
		lasyb10.pfb lcircle1.pfb lcirclew.pfb lcmss8.pfb lcmssb8.pfb \
		lcmssi8.pfb line10.pfb linew10.pfb logo10.pfb logo8.pfb \
		logo9.pfb logobf10.pfb logosl10.pfb
CMEXTRAFONTS=	cmbsy5.pfb cmbsy7.pfb cmmib5.pfb cmmib7.pfb
EULERFONTS=	eurm10.pfb eusb10.pfb eufb10.pfb eurb5.pfb eurb7.pfb \
		eurb10.pfb eurm5.pfb eusb5.pfb eurm7.pfb eusb7.pfb \
		eusm10.pfb eufb5.pfb eufb7.pfb eusm5.pfb eusm7.pfb \
		eufm10.pfb euex10.pfb eufm5.pfb eufm7.pfb
SYMBOLSFONTS=	msbm10.pfb msam5.pfb msam7.pfb msbm5.pfb msbm7.pfb msam10.pfb
CYRILLICFONTS=	wncyss10.pfb wncyb10.pfb wncyi10.pfb wncyr10.pfb wncysc10.pfb

do-install:
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}
	cd ${PREFIX}/${TEXMFDISTDIR} && \
		${TAR} xzUf ${DISTDIR}/${DIST_SUBDIR}/${TETEX_TEXMF_SRC} \
			${EXCLUDE_LIST:S,^,--exclude ,g}
	${INSTALL_DATA} ${FILESDIR}/cslatex.ini ${PREFIX}/${TEXMFDISTDIR}/tex/cslatex/cslatex.ini
	${INSTALL_DATA} ${FILESDIR}/csplain.ini ${PREFIX}/${TEXMFDISTDIR}/tex/csplain/csplain.ini
	${INSTALL_DATA} ${FILESDIR}/t1code.tex ${PREFIX}/${TEXMFDISTDIR}/tex/csplain/t1code.tex
.for F in CM LATEX
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}/fonts/type1/bluesky/${F:L}
	cd ${PREFIX}/${TEXMFDISTDIR}/fonts/type1/bluesky/${F:L} && \
		${LN} -s -f ${${F}FONTS:S,^,${CMPSFONTDIR}/,} .
.endfor
.for F in CMEXTRA EULER SYMBOLS CYRILLIC
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}/fonts/type1/bluesky/${F:L}
	cd ${PREFIX}/${TEXMFDISTDIR}/fonts/type1/bluesky/${F:L} && \
		${LN} -s -f ${${F}FONTS:S,^,${AMSPSFONTDIR}/,} .
.endfor
	cd ${PREFIX}/${TEXMFDISTDIR}/dvips/pstricks && \
		${PATCH} --quiet < ${WRKDIR}/PSTricks.patch && \
		${RM} -f pst-text.pro.orig
	( ${ECHO_CMD} '% ls-R -- filename database for kpathsea; do not change this line.'; \
		${ECHO_CMD} './:'; \
		${ECHO_CMD} 'ls-R'; \
		${ECHO_CMD} '' ) > ${PREFIX}/${TEXMFDISTDIR}/ls-R
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}/xdvi
	${TOUCH} ${PREFIX}/${TEXMFDISTDIR}/xdvi/XDvi
	@if [ -x ${MKTEXLSR} ]; then \
		${MKTEXLSR} ${LOCALBASE}/${TEXMFDISTDIR}; fi

.include <bsd.port.post.mk>

# New ports collection makefile for:	teTeX-texmf
# Date created:		5 June 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX-texmf
PORTVERSION=	3.0
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:1
MASTER_SITE_SUBDIR=	obsolete/systems/unix/teTeX/3.0/distrib
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

CONFLICTS=	latex2e-[0-9]* tex-[0-9]* dvips-[0-9]* xdvi-[0-9]* \
		ja-ptext-base-[0-9]*

.include <bsd.port.pre.mk>

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} \
		TEXMFDISTDIR=${TEXMFDISTDIR} \
		TEXMFCONFIGDIR=${TEXMFCONFIGDIR} \
		MKTEXLSR=${MKTEXLSR} \
		TEXMF_LSR=${TEXMF_LSR}

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

do-install:
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}
	cd ${PREFIX}/${TEXMFDISTDIR} && \
		${TAR} -x -z -U -f ${DISTDIR}/${DIST_SUBDIR}/${TETEX_TEXMF_SRC} \
			${EXCLUDE_LIST:S,^,--exclude ,g}
	cd ${PREFIX}/${TEXMFDISTDIR} && \
		${PATCH} < ${FILESDIR}/extra-patch-latex.ltx && \
		${RM} -f tex/latex/base/latex.ltx.orig
	${INSTALL_DATA} ${FILESDIR}/cslatex.ini ${PREFIX}/${TEXMFDISTDIR}/tex/cslatex/cslatex.ini
	${INSTALL_DATA} ${FILESDIR}/csplain.ini ${PREFIX}/${TEXMFDISTDIR}/tex/csplain/csplain.ini
	${INSTALL_DATA} ${FILESDIR}/t1code.tex ${PREFIX}/${TEXMFDISTDIR}/tex/csplain/t1code.tex
.for T in afm type1
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}/fonts/${T}/bluesky
	cd ${PREFIX}/${TEXMFDISTDIR}/fonts/${T}/bluesky && \
		${LN} -s -f ${LOCALBASE}/share/fonts/cmpsfont/${T} ./cm
	cd ${PREFIX}/${TEXMFDISTDIR}/fonts/${T}/bluesky && \
		${LN} -s -f ${LOCALBASE}/share/fonts/amspsfont/${T} ./ams
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

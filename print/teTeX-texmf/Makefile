# New ports collection makefile for:	teTeX-texmf
# Date created:		5 June 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX-texmf
PORTVERSION=	2.99.13.20050204
PORTREVISION=	0
CATEGORIES=	print
MASTER_SITES=	http://people.freebsd.org/~edwin/ \
		ftp://ftp.dante.de/tex-archive/systems/unix/teTeX-beta/ \
		${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:1
MASTER_SITE_SUBDIR=	systems/unix/teTeX-beta
DISTFILES=	${TETEX_TEXMF_SRC} dvipsk-jpatch-p1.6a1${EXTRACT_SUFX}:1
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	dvipsk-jpatch-p1.6a1${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Thomas Esser's distribution of TeX & friends (texmf tree)

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

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

TETEX_TEXMF_SRC=tetex-texmf-${PORTVERSION}-beta.tar.gz
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

do-install:
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}
	cd ${PREFIX}/${TEXMFDISTDIR} && \
		${TAR} xzUf ${DISTDIR}/${DIST_SUBDIR}/${TETEX_TEXMF_SRC}
	cd ${PREFIX}/${TEXMFDISTDIR}/dvips/pstricks && \
		${PATCH} --quiet < ${WRKDIR}/PSTricks.patch && \
		${RM} -f pst-text.pro.orig
	( ${ECHO_CMD} '% ls-R -- filename database for kpathsea; do not change this line.'; \
		${ECHO_CMD} './:'; \
		${ECHO_CMD} 'ls-R'; \
		${ECHO_CMD} '' ) > ${PREFIX}/${TEXMFDISTDIR}/ls-R
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}/xdvi
	${TOUCH} ${PREFIX}/${TEXMFDISTDIR}/xdvi/XDvi

.include <bsd.port.post.mk>

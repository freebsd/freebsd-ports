# New ports collection makefile for:	teTeX-texmf
# Date created:		5 June 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX-texmf
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:1
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
DISTFILES=	${TETEX_TEXMF} dvipsk-jpatch-p1.6a${EXTRACT_SUFX}:1
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	dvipsk-jpatch-p1.6a${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Thomas Esser's distribution of TeX & friends (texmf tree)

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

CONFLICTS=	latex2e-[0-9]* tex-[0-9]* dvips-[0-9]* xdvi-[0-9]*

.include <bsd.port.pre.mk>

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_SUB=	TEXMF=${TEXMF} \
		MKTEXLSR=${MKTEXLSR} \
		TEXMF_LSR=${TEXMF_LSR}
CONFLICTS=	ja-ptex-base-[0-9]*

TETEX_TEXMF=	tetex-texmf-${PORTVERSION}.tar.gz
TEXMF=		share/texmf
TEXMF_LSR=	${PREFIX}/${TEXMF}/ls-R
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
TEXMFVAR=	share/texmf-var
TEXMFVAR_LSR=	${LOCALBASE}/${TEXMFVAR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

CNFFILES=	DVIPSKCNF XDVIKCNF DVIPDFMCNF
DVIPSKCNF=	dvips/config/config.ps
XDVIKCNF=	xdvi/XDvi
DVIPDFMCNF=	dvipdfm/config/config

TEXMF_IN_SUB=	TEXMF=${TEXMF} PREFIX=${PREFIX}

# XXX: when OPTIONS is set NO_BUILD does not work
do-build:
	@${DO_NADA}

do-install:
	${MKDIR} ${PREFIX}/${TEXMF}
	cd ${PREFIX}/${TEXMF} && \
		${TAR} xzUf ${DISTDIR}/${DIST_SUBDIR}/${TETEX_TEXMF} \
			--exclude "*/texmf.cnf"
	${MV} ${PREFIX}/${TEXMF}/omega/lambda/omegabook/ltpatch.ltx \
		${PREFIX}/${TEXMF}/omega/lambda/omegabook/NOUSE_ltpatch.ltx_
	${INSTALL_DATA} \
		${FILESDIR}/listings.sty \
		${PREFIX}/${TEXMF}/tex/latex/listings/
	cd ${PREFIX}/${TEXMF}/dvips/pstricks && \
		${PATCH} --quiet < ${WRKDIR}/PSTricks.patch && \
		${RM} -f pst-text.pro.orig
.for F in ${CNFFILES}
	${CP} ${PREFIX}/${TEXMF}/${${F}} ${PREFIX}/${TEXMF}/${${F}}.tetex
.endfor

.include <bsd.port.post.mk>

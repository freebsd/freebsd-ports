# New ports collection makefile for:	teTeX-texmf
# Date created:		5 June 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX-texmf
PORTVERSION=	2.0.2
PORTREVISION=	1
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

BUILD_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal

OPTIONS=	LETTERSIZE "Use letter size by default" off

CONFLICTS=	latex2e-[0-9]* tex-[0-9]* dvips-[0-9]* xdvi-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_LETTERSIZE)
FLAVOR+=	letter
DEFAULT_MODE=	tetex-letter
.else
DEFAULT_MODE=	tetex
.endif

# XXX: this does not work
#.if defined(FLAVOR)
#PKGNAMESUFFIX=	${FLAVOR:S,^,-,:Q:S,\\ ,,g:S,\\-,-,g}
#.endif

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_SUB=	TEXMF=${TEXMF} \
		MKTEXLSR=${MKTEXLSR} \
		TEXMF_LSR=${TEXMF_LSR}
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
CONFLICTS=	ja-ptex-base*

TETEX_TEXMF=	tetex-texmf-${PORTVERSION}.tar.gz
TEXMF=		share/texmf
TEXMF_LSR=	${PREFIX}/${TEXMF}/ls-R
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
TEXMFVAR=	share/texmf-var
TEXMFVAR_LSR=	${LOCALBASE}/${TEXMFVAR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

TETEX_MODESW=	${LOCALBASE}/bin/tetex-modesw
PKGINSTALL_SUB=	TETEX_MODESW=${TETEX_MODESW} \
		DEFAULT_MODE=${DEFAULT_MODE}
TETEX_MODES=	tetex tetex-letter

CNFFILES=	DVIPSKCNF XDVIKCNF DVIPDFMCNF
DVIPSKCNF=	dvips/config/config.ps
DVIPSKCNF_IN=	dvips.config.ps
XDVIKCNF=	xdvi/XDvi
XDVIKCNF_IN=	XDvi
DVIPDFMCNF=	dvipdfm/config/config
DVIPDFMCNF_IN=	dvipdfm.config

TEXMF_IN_SUB=	TEXMF=${TEXMF} PREFIX=${PREFIX}

post-configure:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

# XXX: when OPTIONS is set NO_BUILD does not work
do-build:
	@${DO_NADA}

do-install:
	${MKDIR} ${PREFIX}/${TEXMF}
	cd ${PREFIX}/${TEXMF} && \
		${TAR} xUfz ${DISTDIR}/${DIST_SUBDIR}/${TETEX_TEXMF}
	${INSTALL_DATA} \
		${FILESDIR}/listings.sty \
		${PREFIX}/${TEXMF}/tex/latex/listings/
	${RM} -f ${PREFIX}/${TEXMF}/web2c/texmf.cnf
	cd ${PREFIX}/${TEXMF}/dvips/pstricks && \
		${PATCH} --quiet < ${WRKDIR}/PSTricks.patch && \
		${RM} -f pst-text.pro.orig
.for F in ${CNFFILES}
	${RM} -f ${PREFIX}/${TEXMF}/${${F}}
.for M in ${TETEX_MODES}
	${INSTALL_DATA} ${FILESDIR}/${${F}_IN}.${M} ${PREFIX}/${TEXMF}/${${F}}.${M}
.endfor
.endfor
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>

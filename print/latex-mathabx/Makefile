# New ports collection makefile for:	latex-mathabx
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-mathabx
PORTVERSION=	1.0.20031201
CATEGORIES=	print
MASTER_SITES=	http://auemath.aichi-edu.ac.jp/~khotta/ghost/disk1/
DISTFILES=	mathabx${EXTRACT_SUFX} abxtype1${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Math series, aka mathabx MetaFont fontset for TeX/LaTeX

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

USE_ZIP=	YES
NO_BUILD=	YES
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} MFDIR=${MFDIR} \
		TYPE1DIR=${TYPE1DIR} DVIPSDIR=${DVIPSDIR}

TEXMF=		share/texmf
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
CLASS_FILES=	mathabx.dcl mathabx.sty mathabx.tex testmac.tex

MFDIR=		${TEXMFLOCAL}/fonts/source/public/${PORTNAME:S/^latex-//}
MF_FILES=	matha10.mf matha12.mf matha5.mf matha6.mf matha7.mf \
		matha8.mf matha9.mf mathacnt.mf mathadrv.mf matharrw.mf \
		mathastr.mf mathasym.mf mathb10.mf mathb12.mf mathb5.mf \
		mathb6.mf mathb7.mf mathb8.mf mathb9.mf mathbase.mf \
		mathbdel.mf mathbdrv.mf mathbigs.mf mathbsym.mf mathcall.mf \
		mathextr.mf mathfine.mf mathgrey.mf mathhbrw.mf mathineq.mf \
		mathltlk.mf mathmbcb.mf mathprmt.mf mathsmsy.mf mathsubs.mf \
		mathsymb.mf matht10.mf mathu10.mf mathudrv.mf mathusym.mf \
		mathux10.mf mathuxdrv.mf mathx10.mf mathx12.mf mathx5.mf \
		mathx6.mf mathx7.mf mathx8.mf mathx9.mf mathxdrv.mf maydigit.mf

TYPE1DIR=	${TEXMFLOCAL}/fonts/type1/${PORTNAME:S/^latex-//}
TYPE1_FILES=	matha10.pfb matha12.pfb matha5.pfb matha6.pfb matha7.pfb \
		matha8.pfb matha9.pfb mathb10.pfb mathb12.pfb mathb5.pfb \
		mathb6.pfb mathb7.pfb mathb8.pfb mathb9.pfb mathu10.pfb \
		mathux10.pfb mathx10.pfb mathx12.pfb mathx5.pfb mathx6.pfb \
		mathx7.pfb mathx8.pfb mathx9.pfb

DVIPSDIR=	${TEXMFLOCAL}/dvips/${PORTNAME:S/^latex-//}
DVIPS_FILES=	mathabx.map

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${WRKSRC}/mathtest.tex\
		${CLASS_FILES:S@^@${WRKSRC}/texinputs/@}\
		${PREFIX}/${CLASSDIR}
	${MKDIR} ${PREFIX}/${MFDIR}
	${INSTALL_DATA} ${MF_FILES:S@^@${WRKSRC}/source/@}\
		${PREFIX}/${MFDIR}
	${MKDIR} ${PREFIX}/${TYPE1DIR}
	${INSTALL_DATA} ${TYPE1_FILES:S@^@${WRKDIR}/abxtype1/pfb/@}\
		${PREFIX}/${TYPE1DIR}
	${MKDIR} ${PREFIX}/${DVIPSDIR}
	${INSTALL_DATA} ${DVIPS_FILES:S@^@${WRKDIR}/abxtype1/map/@}\
		${PREFIX}/${DVIPSDIR}

post-install:
	${MKTEXLSR}
	@${SED} -e 's,%%PREFIX%%,${PREFIX},;s,%%TEXMF%%,${TEXMF},'\
		${PKGMESSAGE}

.include <bsd.port.mk>

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

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_ZIP=	YES
NO_BUILD=	YES
PLIST_SUB=	TEXMF=${TEXMF} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR} MFDIR=${MFDIR}
PLIST_SUB+=	TYPE1DIR=${TYPE1DIR} DVIPSDIR=${DVIPSDIR}

TEXMF=		share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMF}/tex/latex/${PORTNAME:S/^latex-//}
MFDIR=		${TEXMF}/fonts/source/public/${PORTNAME:S/^latex-//}
TYPE1DIR=	${TEXMF}/fonts/type1/${PORTNAME:S/^latex-//}
DVIPSDIR=	${TEXMF}/dvips/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	mathabx.dcl
CLASS_FILES+=	mathabx.sty
CLASS_FILES+=	mathabx.tex
CLASS_FILES+=	testmac.tex

MF_FILES=	matha10.mf
MF_FILES+=	matha12.mf
MF_FILES+=	matha5.mf
MF_FILES+=	matha6.mf
MF_FILES+=	matha7.mf
MF_FILES+=	matha8.mf
MF_FILES+=	matha9.mf
MF_FILES+=	mathacnt.mf
MF_FILES+=	mathadrv.mf
MF_FILES+=	matharrw.mf
MF_FILES+=	mathastr.mf
MF_FILES+=	mathasym.mf
MF_FILES+=	mathb10.mf
MF_FILES+=	mathb12.mf
MF_FILES+=	mathb5.mf
MF_FILES+=	mathb6.mf
MF_FILES+=	mathb7.mf
MF_FILES+=	mathb8.mf
MF_FILES+=	mathb9.mf
MF_FILES+=	mathbase.mf
MF_FILES+=	mathbdel.mf
MF_FILES+=	mathbdrv.mf
MF_FILES+=	mathbigs.mf
MF_FILES+=	mathbsym.mf
MF_FILES+=	mathcall.mf
MF_FILES+=	mathextr.mf
MF_FILES+=	mathfine.mf
MF_FILES+=	mathgrey.mf
MF_FILES+=	mathhbrw.mf
MF_FILES+=	mathineq.mf
MF_FILES+=	mathltlk.mf
MF_FILES+=	mathmbcb.mf
MF_FILES+=	mathprmt.mf
MF_FILES+=	mathsmsy.mf
MF_FILES+=	mathsubs.mf
MF_FILES+=	mathsymb.mf
MF_FILES+=	matht10.mf
MF_FILES+=	mathu10.mf
MF_FILES+=	mathudrv.mf
MF_FILES+=	mathusym.mf
MF_FILES+=	mathux10.mf
MF_FILES+=	mathuxdrv.mf
MF_FILES+=	mathx10.mf
MF_FILES+=	mathx12.mf
MF_FILES+=	mathx5.mf
MF_FILES+=	mathx6.mf
MF_FILES+=	mathx7.mf
MF_FILES+=	mathx8.mf
MF_FILES+=	mathx9.mf
MF_FILES+=	mathxdrv.mf
MF_FILES+=	maydigit.mf

TYPE1_FILES=	matha10.pfb
TYPE1_FILES+=	matha12.pfb
TYPE1_FILES+=	matha5.pfb
TYPE1_FILES+=	matha6.pfb
TYPE1_FILES+=	matha7.pfb
TYPE1_FILES+=	matha8.pfb
TYPE1_FILES+=	matha9.pfb
TYPE1_FILES+=	mathb10.pfb
TYPE1_FILES+=	mathb12.pfb
TYPE1_FILES+=	mathb5.pfb
TYPE1_FILES+=	mathb6.pfb
TYPE1_FILES+=	mathb7.pfb
TYPE1_FILES+=	mathb8.pfb
TYPE1_FILES+=	mathb9.pfb
TYPE1_FILES+=	mathu10.pfb
TYPE1_FILES+=	mathux10.pfb
TYPE1_FILES+=	mathx10.pfb
TYPE1_FILES+=	mathx12.pfb
TYPE1_FILES+=	mathx5.pfb
TYPE1_FILES+=	mathx6.pfb
TYPE1_FILES+=	mathx7.pfb
TYPE1_FILES+=	mathx8.pfb
TYPE1_FILES+=	mathx9.pfb

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

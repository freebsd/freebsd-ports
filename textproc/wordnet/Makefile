# New ports collection makefile for:	wordnet
# Date created:		26 Feb 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	wordnet
PORTVERSION=	1.6
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.princeton.edu/pub/wordnet/ \
		ftp://ftp.ims.uni-stuttgart.de/pub/WordNet/${PORTVERSION}/
DISTFILES=	wn16.unix.tar.gz

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

MAN1=		wn.1 wnb.1 wnintro.1
MAN3=		binsrch.3 morph.3 wnintro.3 wnsearch.3 wnutil.3
MAN5=		cntlist.5 glossidx.5 lexnames.5 senseidx.5 taglist.5 \
		wndb.5 wninput.5 wnintro.5
MAN7=		morphy.7 uniqbeg.7 wngloss.7 wngroups.7 wnintro.7 \
		wnlicens.7 wnpkgs.7 wnstats.7
MANCOMPRESSED=	maybe

TCL_DVER=	8.3
SCRIPTS_ENV+=	TCL_DVER=${TCL_DVER}
MAKE_ENV+=	TCL_DVER=${TCL_DVER}
PLIST_SUB+=	TCL_DVER=${TCL_DVER}
# Parallel build is faster even on a single cpu machine:
MAKE_ARGS=	-j 2

post-extract:
	# bin and lib contain useless pre-built binaries:
	${RM} -rf ${WRKSRC}/bin ${WRKSRC}/lib

.include <bsd.port.mk>

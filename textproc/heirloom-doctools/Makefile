# Ports collection makefile for:  heirloom-doctools
# Date created:			  Saturday, 3 December 2005
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	heirloom-doctools
PORTVERSION=	0.0.080407
CATEGORIES=	textproc
MASTER_SITES=	SF/heirloom/${PORTNAME}/080407
DISTNAME=	${PORTNAME}-${PORTVERSION:S,0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable and enhanced troff, nroff, and related utilities

USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	#empty
MAKE_ENV+=	INSTALL=${INSTALL} \
		BINDIR=${BINDIR} \
		LIBDIR=${LIBDIR} \
		PUBDIR=${PUBDIR} \
		MANDIR=${MANDIR} \
		MACDIR=${MACDIR} \
		FNTDIR=${FNTDIR} \
		PSTDIR=${PSTDIR} \
		TABDIR=${TABDIR} \
		HYPDIR=${HYPDIR} \
		REFDIR=${REFDIR}
MAKEFILE=	makefile
PLIST_SUB=	PORTNAME=${PORTNAME}

MACDIR?=	${DATADIR}/tmac
FNTDIR?=	${DATADIR}/font
TABDIR?=	${DATADIR}/nterm
HYPDIR?=	${DATADIR}/hyphen
REFDIR?=	${PREFIX}/libexec/${PORTNAME}/reftools
PUBDIR?=	${DATADIR}/pub
BINDIR?=	${PREFIX}/bin
LIBDIR?=	${PREFIX}/libexec/${PORTNAME}
PSTDIR?=	${DATADIR}/font/devpost/postscript
MANDIR?=	${PREFIX}/man

MAN1+=	addbib.1 checknr.1 dpost.1 eqn.1 grap.1 lookbib.1 nroff.1	\
	otfdump.1 pic.1 picpack.1 ptx.1 refer.1 roffbib.1 soelim.1	\
	sortbib.1 tbl.1 troff.1 vgrind.1
MAN7+= 	eqnchar.7 mcolor.7 mpictures.7
MLINKS+=	lookbib.1 indxbib.1 \
		eqn.1 checkeq.1 \
		eqn.1 neqn.1

PORTDOCS=	CHANGES README LICENSE

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

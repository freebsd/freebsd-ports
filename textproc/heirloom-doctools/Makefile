# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	heirloom-doctools
PORTVERSION=	0.0.080407
CATEGORIES=	textproc
MASTER_SITES=	SF/heirloom/${PORTNAME}/080407
DISTNAME=	${PORTNAME}-${PORTVERSION:S,0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable and enhanced troff, nroff, and related utilities

USES=	gmake
USE_BZIP2=	yes
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
		REFDIR=${REFDIR} \
		ROOT=${STAGEDIR}
MAKEFILE=	makefile
PLIST_SUB=	LIBEXECDIR=libexec/${PORTNAME}

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

PORTDOCS=	 *

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

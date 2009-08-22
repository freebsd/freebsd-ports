# New ports collection makefile for:	metauml
# Date created:		2007-08-29
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	metauml
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}_lib_${PORTVERSION}.tgz ${PORTNAME}_manual_${PORTVERSION}.pdf lop-release.tgz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}_lib_${PORTVERSION}.tgz lop-release.tgz

MAINTAINER=	tota@rtfm.jp
COMMENT=	A MetaPost library for typesetting UML diagrams

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} MPDIR=${MPDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
MPDIR=		${TEXMFDIR}/metapost/${PORTNAME}

NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}_lib
EXAMPLES=	*.1 *.jpg *.mp lop lop.html lop.pdf lop.tex

do-install:
	${MKDIR} ${PREFIX}/${MPDIR}
	${INSTALL_DATA} ${WRKSRC}/thrunk/*.mp ${PREFIX}/${MPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}_manual_${PORTVERSION}.pdf ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLES}
	${INSTALL_DATA} ${WRKDIR}/${example} ${EXAMPLESDIR}
.endfor
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>

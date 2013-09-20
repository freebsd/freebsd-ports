# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	metauml
PORTVERSION=	0.2.5
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/:lib \
		SF/${PORTNAME}/${PORTNAME}_manual/${PORTVERSION}/:man \
		SF/${PORTNAME}/${PORTNAME}_lop/1.0/:patterns
DISTFILES=	${PORTNAME}_lib_${PORTVERSION}.tgz:lib \
		${PORTNAME}_manual_${PORTVERSION}.pdf:man \
		lop-release.tgz:patterns
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}_lib_${PORTVERSION}.tgz lop-release.tgz

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A MetaPost library for typesetting UML diagrams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/thrunk/License

USE_TEX=	latex
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} MPDIR=${MPDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
MPDIR=		${TEXMFDIR}/metapost/${PORTNAME}

NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}_lib
EXAMPLES=	*.1 *.jpg *.mp lop lop.html lop.pdf lop.tex

NO_STAGE=	yes
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

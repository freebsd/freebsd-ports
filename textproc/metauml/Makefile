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
COMMENT=	MetaPost library for typesetting UML diagrams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/thrunk/License

USE_TEX=	latex
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} MPDIR=${MPDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
MPDIR=		${TEXMFDIR}/metapost/${PORTNAME}

NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}_lib
PORTDOCS=	${PORTNAME}_manual_${PORTVERSION}.pdf
PORTEXAMPLES=	*.1 *.jpg *.mp lop lop.html lop.pdf lop.tex

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MPDIR}
	${INSTALL_DATA} ${WRKSRC}/thrunk/*.mp ${STAGEDIR}${PREFIX}/${MPDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for example in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKDIR}/${example} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

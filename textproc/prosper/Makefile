# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	prosper
PORTVERSION=	1.00.4
PORTREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	SF \
		SF/${PORTNAME}/contributed%20styles/1.0.0:contrib
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		contrib-prosper-1.0.0.tar.gz:contrib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX class for writing transparencies

NO_BUILD=	yes
USES=		ghostscript:run
USE_TEX=	latex
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

WRKSRC=		${WRKDIR}/${PORTNAME}

TEXMFDIR?=	share/texmf
LPROSPERDIR=	${TEXMFDIR}/tex/latex/prosper
PROSPERDIR=	${PREFIX}/${LPROSPERDIR}

PLIST_SUB=	PROSPERDIR=${LPROSPERDIR} \
		MKTEXLSR=${MKTEXLSR}

DOCS=		AUTHORS ChangeLog FAQ INSTALL NEWS README TODO \
		TROUBLESHOOTINGS doc/compilation.eps doc/compilation.fig \
		doc/prosper-doc.pdf doc/prosper-doc.tex \
		doc/prosper-structure.eps doc/prosper-structure.fig \
		doc/prosper-tour.pdf doc/prosper-tour.ps doc/prosper-tour.tex \
		doc/rotation.ps doc/rotation.tex

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@(cd ${WRKDIR}/contrib-prosper-1.0.0 && ${FIND} . | \
		${CPIO} --quiet -dump ${WRKSRC}/contrib)

do-install:
	@${MKDIR} ${STAGEDIR}${PROSPERDIR}/contrib/img
	@${MKDIR} ${STAGEDIR}${PROSPERDIR}/designer
	@${MKDIR} ${STAGEDIR}${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/*.sty ${STAGEDIR}${PROSPERDIR}
	${INSTALL_DATA} ${WRKSRC}/*.cls ${STAGEDIR}${PROSPERDIR}
	${INSTALL_DATA} ${WRKSRC}/img/*.gif ${STAGEDIR}${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/img/*.ps  ${STAGEDIR}${PROSPERDIR}/img
	(cd ${WRKSRC}/contrib && ${INSTALL_DATA} *.sty *.ps *.tex \
		${STAGEDIR}${PROSPERDIR}/contrib)
	(cd ${WRKSRC}/contrib/img && ${INSTALL_DATA} *.ps *.eps *.gif \
		${STAGEDIR}${PROSPERDIR}/contrib/img)
	${INSTALL_DATA} ${WRKSRC}/designer/prosper* \
		${STAGEDIR}${PROSPERDIR}/designer
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/doc-examples/Example* \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

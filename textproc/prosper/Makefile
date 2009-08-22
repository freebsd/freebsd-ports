# Ports collection makefile for:	prosper
# Date created:			Sun Feb 24, 2002
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	prosper
PORTVERSION=	1.00.4
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} contrib-prosper-1.0.0.tar.gz

MAINTAINER=	vs@FreeBSD.org
COMMENT=	LaTeX class for writing transparencies

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_BUILD=	yes
USE_GHOSTSCRIPT_RUN=	yes
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
EXAMPLES_DIR=	doc/doc-examples

post-extract:
	@${CP} -r ${WRKDIR}/contrib-prosper-1.0.0/* ${WRKSRC}/contrib/

do-install:
	@${MKDIR} ${PROSPERDIR}/contrib/img
	@${MKDIR} ${PROSPERDIR}/designer
	@${MKDIR} ${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/*.sty ${PROSPERDIR}
	${INSTALL_DATA} ${WRKSRC}/*.cls ${PROSPERDIR}
	${INSTALL_DATA} ${WRKSRC}/img/*.gif ${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/img/*.ps  ${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/contrib/*.sty ${PROSPERDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/*.ps  ${PROSPERDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/*.tex ${PROSPERDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/img/*.ps ${PROSPERDIR}/contrib/img
	${INSTALL_DATA} ${WRKSRC}/contrib/img/*.eps ${PROSPERDIR}/contrib/img
	${INSTALL_DATA} ${WRKSRC}/contrib/img/*.gif ${PROSPERDIR}/contrib/img
	${INSTALL_DATA} ${WRKSRC}/designer/prosper* ${PROSPERDIR}/designer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES_DIR}/Example*
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>

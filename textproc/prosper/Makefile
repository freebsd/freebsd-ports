# Ports collection makefile for:	prosper
# Date created:			Sun Feb 24, 2002
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	prosper
PORTVERSION=	1.00.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} PPRblends.sty.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Prosper is a LaTeX class for writing transparencies

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_BUILD=	yes
USE_GHOSTSCRIPT_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

TEXMFDIR?=	share/texmf
LPROSPERDIR=	${TEXMFDIR}/tex/latex/prosper
PROSPERDIR=	${PREFIX}/${LPROSPERDIR}

PLIST_SUB=	PROSPERDIR=${LPROSPERDIR}

DOCS=		AUTHORS ChangeLog FAQ INSTALL NEWS README TODO \
		TROUBLESHOOTINGS doc/compilation.eps doc/compilation.fig \
		doc/prosper-doc.pdf doc/prosper-doc.tex \
		doc/prosper-structure.eps doc/prosper-structure.fig \
		doc/prosper-tour.pdf doc/prosper-tour.ps doc/prosper-tour.tex \
		doc/rotation.ps doc/rotation.tex
EXAMPLES_DIR=	doc/doc-examples

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

post-extract:
	@${GZCAT} -c ${DISTDIR}/PPRblends.sty.gz > \
			${WRKSRC}/contrib/PPRblends.sty

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
	${INSTALL_DATA} ${WRKSRC}/designer/prosper* ${PROSPERDIR}/designer
	mktexlsr
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

.include <bsd.port.mk>

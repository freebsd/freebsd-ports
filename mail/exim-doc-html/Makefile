# New ports collection makefile for:	exim-doc-html
# Date created:		27 November 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exim
PORTVERSION=	4.50
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_EXIM}
MASTER_SITE_SUBDIR=	exim4
PKGNAMESUFFIX=	-doc-${DOCFORMAT}
DISTNAME=	exim-${DISTDOCFORMAT}-${PORTVERSION}
DIST_SUBDIR=	exim

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation for the Exim MTA in multiple formats

USE_BZIP2=	yes

DOCFORMAT?=	html
DISTDOCFORMAT?=	${DOCFORMAT}

.if !defined(NOPORTDOCS)
.if ${DOCFORMAT} == "html"
PORTDOCS=	html
.elif ${DOCFORMAT} == "pdf"
PORTDOCS=	*.pdf
.elif ${DOCFORMAT} == "postscript"
PORTDOCS=	*.ps
.elif ${DOCFORMAT} == "info"
PLIST=		${PKGDIR}/pkg-plist_${DOCFORMAT}
.else
pre-everything::
	@ ${ECHO} 'ERROR: invalid value for DOCFORMAT: "${DOCFORMAT}"'
	@ ${ECHO} 'Possible values are "html", "pdf", "postscript" and "info".'
	@ ${FALSE}
.endif
.endif

do-build:
.if ${DOCFORMAT} == "info"
	@ cd ${WRKSRC}/doc; \
		makeinfo --no-split --output exim.info spec.texinfo; \
		makeinfo --no-split --output exim_filter.info filter.texinfo
.else
	@ ${DO_NADA}
.endif

do-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.if ${DOCFORMAT} == "html"
	@ ${MKDIR} ${DOCSDIR}/html
	@ ${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
	@ ${INSTALL_DATA} ${WRKSRC}/doc/html/*.gif ${DOCSDIR}/html
.elif ${DOCFORMAT} == "pdf"
	@ ${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
.elif ${DOCFORMAT} == "postscript"
	@ ${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
.elif ${DOCFORMAT} == "info"
	@ ${INSTALL_DATA} ${WRKSRC}/doc/exim.info ${PREFIX}/info
	@ install-info --section="Exim" \
		--entry "* User guide: (exim).           Exim manual" \
		${PREFIX}/info/exim.info ${PREFIX}/info/dir
	@ ${INSTALL_DATA} ${WRKSRC}/doc/exim_filter.info ${PREFIX}/info
	@ install-info --section="Exim" \
		--entry "* Filtering: (exim_filter).     Filtering mail with Exim" \
		${PREFIX}/info/exim_filter.info ${PREFIX}/info/dir
.else
	@${FALSE}
.endif
.endif

.include <bsd.port.mk>

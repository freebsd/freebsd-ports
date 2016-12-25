# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exim
PORTVERSION=	4.87
CATEGORIES=	mail
MASTER_SITES=	EXIM
MASTER_SITE_SUBDIR=	/exim4/ \
			/exim4/old/
PKGNAMESUFFIX=	-doc-${DOCFORMAT}
DISTNAME=	exim-${DISTDOCFORMAT}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	exim

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Documentation for the Exim MTA in multiple formats

USES=		tar:bzip2

DOCFORMAT?=	html
DISTDOCFORMAT?=	${DOCFORMAT}
AVAILABLE_FORMATS=	html \
					pdf \
					postscript
NO_BUILD=	yes

.if make(makesum) && !defined(FETCH_ALL)
.error "You forgot to define FETCH_ALL to create the sane distinfo"
.endif

.if defined(FETCH_ALL)
. for _df in ${AVAILABLE_FORMATS}
.  if ${_df} != ${DOCFORMAT}
DISTFILES+=	exim-${_df}-${PORTVERSION}${EXTRACT_SUFX}:exim
.  endif
. endfor
.endif

.if ${DOCFORMAT} == "html"
PORTDOCS=	html
.elif ${DOCFORMAT} == "pdf"
PORTDOCS=	*.pdf
.elif ${DOCFORMAT} == "postscript"
PORTDOCS=	*.ps
.elif ${DOCFORMAT} == "info"
IGNORE=	exim no longer provides documentation in info format
.else
pre-everything::
	@ ${ECHO} 'ERROR: invalid value for DOCFORMAT: "${DOCFORMAT}"'
	@ ${ECHO} 'Possible values are "html", "pdf", and "postscript".'
	@ ${FALSE}
.endif

do-install:
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
.if ${DOCFORMAT} == "html"
	${TAR} -C ${WRKSRC}/doc -cf - html | \
		${TAR} --unlink -C ${STAGEDIR}${DOCSDIR} -xf -
.elif ${DOCFORMAT} == "pdf"
	@ ${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
.elif ${DOCFORMAT} == "postscript"
	@ ${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}
.else
	@${FALSE}
.endif

.include <bsd.port.mk>

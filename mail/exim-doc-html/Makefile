# New ports collection makefile for:	exim-doc-html
# Date created:		27 November 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exim-doc-${DOCFORMAT}
PORTVERSION=	4.10
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		http://www.exim.org/ftp/exim4/ \
		ftp://ftp.is.co.za/networking/mail/transport/exim/
DISTNAME=	exim-${DOCFORMAT}-${PORTVERSION}

MAINTAINER=	sheldonh@FreeBSD.org

USE_BZIP2=	yes
NO_BUILD=	yes
DOCSDIR=	${PREFIX}/share/doc/exim
PLIST=		${WRKDIR}/pkg-plist

DOCFORMAT?=	html
.if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "pdf" && ${DOCFORMAT} != "postscript"
.BEGIN:
	@ ${ECHO} 'ERROR: invalid value for DOCFORMAT: "${DOCFORMAT}"'
	@ ${ECHO} 'Possible values are "html", "pdf" and "postscript".'
	@ ${FALSE}
.endif

pre-install:
	@ ${CP} ${PKGDIR}/pkg-plist_${DOCFORMAT} ${PLIST}

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
.endif
.endif

.include <bsd.port.mk>

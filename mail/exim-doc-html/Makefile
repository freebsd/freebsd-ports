# New ports collection makefile for:	exim-doc-html
# Date created:		27 November 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exim-doc-${DOCFORMAT}
PORTVERSION=	4.20
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/mail/exim/%SUBDIR%/ \
		ftp://ftp.easynet.be/exim/%SUBDIR%/ \
		ftp://mirror.direct.ca/pub/exim/%SUBDIR%/ \
		ftp://mirror.kn.vutbr.cz/pub/ftp.exim.org/%SUBDIR%/ \
		ftp://sunsite.auc.dk/pub/mail/exim/%SUBDIR%/ \
		ftp://ftp.doc.cs.univ-paris8.fr/mirrors/ftp.exim.org/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/mail/exim/%SUBDIR%/ \
		ftp://ftp.tin.org/pub/mail/exim/%SUBDIR%/ \
		ftp://ftp.freenet.de/pub/ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/%SUBDIR%/ \
		ftp://nagoya.linux.or.jp/mirror/exim/%SUBDIR%/ \
		http://exim.psshee.com/ftp/%SUBDIR%/ \
		ftp://ftp.nl.uu.net/pub/unix/mail/exim/%SUBDIR%/ \
		ftp://ftp.demon.nl/pub/mirrors/exim/%SUBDIR%/ \
		ftp://ftp.easynet.nl/mirror/exim/%SUBDIR%/ \
		ftp://sunsite.uio.no/pub/mail/exim/%SUBDIR%/ \
		http://sunsite.icm.edu.pl/pub/unix/mail/exim/%SUBDIR%/ \
		ftp://ftp.smux.net/pub/exim/%SUBDIR%/ \
		ftp://ftp.is.co.za/networking/mail/mta/exim/%SUBDIR%/ \
		ftp://sunsite.cnlab-switch.ch/mirror/exim/%SUBDIR%/ \
		ftp://ftp.exim.org/pub/exim/%SUBDIR%/ \
		http://www.us.exim.org/ftp/%SUBDIR%/ \
		http://exim.stanford.edu/ftp/pub/exim/%SUBDIR%/ \
		ftp://ftp.fsckit.net/pub/exim/%SUBDIR%/
MASTER_SITE_SUBDIR=	exim4
DISTNAME=	exim-${DOCFORMAT}-${PORTVERSION}
DIST_SUBDIR=	exim

MAINTAINER=	sheldonh@FreeBSD.org
COMMENT=	Documentation for the Exim MTA in multiple formats

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

# New ports collection makefile for:	tidy
# Date created:		27 Oct 1998
# Whom:			Abel Chow <achow@transoft.net>
#
# $FreeBSD$
#

PORTNAME=	tidy
PORTVERSION=	030208
CATEGORIES=	www
MASTER_SITES=	http://tidy.sourceforge.net/src/%SUBDIR%/	\
		http://tidy.sourceforge.net/docs/
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	-devel
DISTNAME=	tidy_src
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	thierry@pompo.net

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes

#MAN1=		tidy.1

.if !defined(NOPORTDOCS)
DOCVER=		021222
DISTFILES+=	tidy_docs_${DOCVER}${EXTRACT_SUFX}
DOCFILES=	Overview.html faq.html grid.gif pending.html	\
		quickref.html release-notes.html tidy.css tidy.gif
APIEXT=		css html js png
.endif

BIN2STRIP=	tidy tab2space

pre-install:
	@if [ -f ${LOCALBASE}/bin/tidy ]; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Conflict: please deinstall the port bin/tidy." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi

post-install:
.for pgm in ${BIN2STRIP}
	@${STRIP_CMD} ${PREFIX}/bin/${pgm}
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/htmldoc/${docfile} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/api
.for ext in ${APIEXT}
	@${CP} -p ${WRKSRC}/htmldoc/api/*.${ext} ${DOCSDIR}/api
.endfor
	@${CHOWN} -R ${MANOWN}:${MANGRP} ${DOCSDIR}/api
	@${ECHO_MSG} "===>   Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>

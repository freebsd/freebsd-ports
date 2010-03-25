# New ports collection makefile for:    skipfish
# Date created:         2010-03-25
# Whom:                 rpsfa@rit.edu
#
# $FreeBSD$

PORTNAME=	skipfish
PORTVERSION=	1.11b
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rpsfa@rit.edu
COMMENT=	A fully automated, active web application security reconnaissance tool

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	README COPYING ChangeLog
.endif

post-patch:
	@${SED} -ie 's:assets:${DATADIR}/assets:g' ${WRKSRC}/report.c
	@${SED} -ie 's:assets/:${DATADIR}/assets/:g' ${WRKSRC}/skipfish.c
	@${SED} -ie 's:skipfish.wl:${DATADIR}/dictionaries/default.wl:g' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skipfish ${PREFIX}/bin/skipfish
	(cd ${WRKSRC}/assets/ && ${COPYTREE_SHARE} . ${DATADIR}/assets/)
	(cd ${WRKSRC}/dictionaries/ && ${COPYTREE_SHARE} . ${DATADIR}/dictionaries/)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for doc in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.	endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

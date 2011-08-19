# New ports collection makefile for:    skipfish
# Date created:         2010-03-25
# Whom:                 rpsfa@rit.edu
#
# $FreeBSD$

PORTNAME=	skipfish
PORTVERSION=	2.03b
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A fully automated, active web application security reconnaissance tool

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn

SUB_FILES=	pkg-message

MAN1=		skipfish.1

.if !defined(NOPORTDOCS)
PORTDOCS=	README COPYING ChangeLog
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's:"skipfish.wl":"${DATADIR}/dictionaries/complete.wl":' \
		-e 's:"assets":"${DATADIR}/assets":' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skipfish ${PREFIX}/bin/skipfish
	${INSTALL_SCRIPT} ${WRKSRC}/sfscandiff ${PREFIX}/bin/sfscandiff
	${INSTALL_MAN} ${WRKSRC}/skipfish.1 ${PREFIX}/man/man1
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

.include <bsd.port.post.mk>

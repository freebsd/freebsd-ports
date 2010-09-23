# New ports collection makefile for:	ccsrch
# Date created:		2010-07-21
# Whom:			Pavel I Volkov <pavelivolkov@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	ccsrch
PORTVERSION=	1.0.3
CATEGORIES=	security
MASTER_SITES=	http://downloads.sourceforge.net/project/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	Is a tool that searches for credit card numbers (PAN) and track data

FETCH_ARGS=	-pRr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	README readme.html
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.post.mk>

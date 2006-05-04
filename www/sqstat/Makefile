# New ports collection makefile for:	sqstat
# Date created:		4 May 2006
# Whom:			Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqstat
PORTVERSION=	0.9.5
CATEGORIES=	www
MASTER_SITES=	http://samm.kiev.ua/sqstat/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A script which allows to look through active squid users connections

USE_PHP=	pcre
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

SQSTATDIR?=	share/${PORTNAME}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	SQSTATDIR=${SQSTATDIR}

PLIST_DIRS=	${SQSTATDIR}
PLIST_FILES=	${SQSTATDIR}/sqstat.css ${SQSTATDIR}/sqstat.php
PORTDOCS=	CHANGES LICENSE README TODO

do-install:
	@${MKDIR} ${PREFIX}/${SQSTATDIR}; \
	for f in ${PLIST_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f##*/} ${PREFIX}/${SQSTATDIR}; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

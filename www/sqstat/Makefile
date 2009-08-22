# New ports collection makefile for:	sqstat
# Date created:		4 May 2006
# Whom:			Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqstat
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://samm.kiev.ua/sqstat/ \
		SF/sqstat/sqstat/sqstat-${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A script which allows to look through active squid users connections

USE_PHP=	pcre session
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

SQSTATDIR?=	share/${PORTNAME}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	SQSTATDIR=${SQSTATDIR}

PLIST_DIRS=	${SQSTATDIR}
PLIST_FILES=	${SQSTATDIR}/arrow.gif ${SQSTATDIR}/sqstat.class.php \
		${SQSTATDIR}/sqstat.css ${SQSTATDIR}/sqstat.php \
		${SQSTATDIR}/zhabascript.js \
		${SQSTATDIR}/config.inc.php.defaults
PORTDOCS=	CHANGES FAQ LICENSE README TODO

do-install:
	@${MKDIR} ${PREFIX}/${SQSTATDIR}; \
	for f in ${PLIST_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f##*/} ${PREFIX}/${SQSTATDIR}; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$f ${DOCSDIR}; \
	done
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

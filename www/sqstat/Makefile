# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqstat
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://samm.kiev.ua/sqstat/ \
		SF/sqstat/sqstat/sqstat-${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Script which allows to look through active squid users connections

BROKEN_powerpc64=	Does not build

USE_PHP=	pcre session
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

SQSTATDIR?=	share/${PORTNAME}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	SQSTATDIR=${SQSTATDIR}

PLIST_FILES=	${SQSTATDIR}/arrow.gif ${SQSTATDIR}/sqstat.class.php \
		${SQSTATDIR}/sqstat.css ${SQSTATDIR}/sqstat.php \
		${SQSTATDIR}/zhabascript.js \
		${SQSTATDIR}/config.inc.php.defaults
PORTDOCS=	CHANGES FAQ LICENSE README TODO

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SQSTATDIR}; \
	for f in ${PLIST_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f##*/} ${STAGEDIR}${PREFIX}/${SQSTATDIR}; \
	done
	@${MKDIR} ${STAGEDIR}${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$f ${STAGEDIR}${DOCSDIR}; \
	done

.include <bsd.port.mk>

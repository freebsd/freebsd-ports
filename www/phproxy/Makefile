# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	phproxy
PORTVERSION=	0.5b2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/poxy/PHProxy/0.5%20beta%202
DISTNAME=	poxy-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP based web proxy

BROKEN_powerpc64=	Does not build

NO_BUILD=	YES
WANT_PHP_WEB=	YES
USES=		zip:infozip
USE_PHP=	ctype pcre
EXTRACT_AFTER_ARGS+=	-d ${WRKSRC}
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

DOCFILES=	ChangeLog.txt LICENSE.txt README.txt TODO.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

	@${RM} ${WRKSRC}/*.txt
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/)

.include <bsd.port.mk>

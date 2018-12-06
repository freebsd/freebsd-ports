# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kplaylist
PORTVERSION=	1.8.505
PORTREVISION?=	2
CATEGORIES=	www multimedia
MASTER_SITES=	http://www.kplaylist.net/archive.php?file=1.8.505&tar=true/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP based music database

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

IGNORE_WITH_PHP=	71 72 73

RUN_DEPENDS=	lame:audio/lame \
		oggenc:audio/vorbis-tools \
		zip:archivers/zip

USES=		php
USE_PHP=	curl mysql session iconv

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	"@(${WWWOWN},${WWWGRP},) %%WWWDIR%%/index.php" \
		"@dir(${WWWOWN},${WWWGRP},) %%WWWDIR%%"

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${CP} kplaylist.1.8.505.php \
		${STAGEDIR}${WWWDIR}/index.php

.include <bsd.port.mk>

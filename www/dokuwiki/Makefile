# Created by: Chin-San Huang <chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	dokuwiki
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g}
CATEGORIES=	www
MASTER_SITES=	http://download.dokuwiki.org/src/dokuwiki/
DISTNAME=	${DIST_VER}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Simple and easy to use wiki, no database required

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

DIST_VER=	${PORTNAME}-2015-08-10a
USE_PHP=	gd mbstring openssl pcre session xml zlib
NO_ARCH=	YES
NO_BUILD=	YES
WANT_PHP_WEB=	YES

USES=		cpe tar:tgz

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/bin/*.php
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${RM} ${WRKSRC}/data/deleted.files

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

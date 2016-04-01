# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sxweb
PORTVERSION=	0.9.0
CATEGORIES=	www
MASTER_SITES=	http://cdn.skylable.com/source/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	SXDrive Web app

RUN_DEPENDS=	sxinit:net-mgmt/sx

USES=		cpe
USE_PHP=	ctype curl dom gd hash iconv json mbstring mysql mysqli \
		pcre pdo pdo_mysql posix session simplexml sockets spl \
		xml xmlreader xmlwriter

WANT_PHP_WEB=	yes

NO_BUILD=	yes
SXWEB_USERNAME?=	${WWWOWN}
SXWEB_GROUPNAME?=	${WWWGRP}
PLIST_SUB=	SXWEB_USERNAME=${SXWEB_USERNAME} \
		SXWEB_GROUPNAME=${SXWEB_GROUPNAME}
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data

.include <bsd.port.mk>

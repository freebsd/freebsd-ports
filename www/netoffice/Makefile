# Created by: Marcelo Araujo <araujo@bsdmail.org>
# $FreeBSD$

PORTNAME=	netoffice
PORTVERSION=	2.6.0b2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetOffice is a free web based project-management environment

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

IGNORE_WITH_PHP=	71 72 73

NO_BUILD=	yes
NO_ARCH=	yes
USES=		php:web mysql
USE_PHP=	mysql pcre zlib session xml gd

WEBOWN?=	www
WEBGRP?=	www
APACHEDIR=	${LOCALBASE}/www/
INSTALLDIR=	${APACHEDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${STAGEDIR}${INSTALLDIR}

.include <bsd.port.mk>

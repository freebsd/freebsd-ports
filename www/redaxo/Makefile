# Created by: Marco Steinbach <coco@executive-computing.de>
# $FreeBSD$

PORTNAME=	redaxo
PORTVERSION=	4.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.redaxo.org/files/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}

MAINTAINER=	coco@executive-computing.de
COMMENT=	REDAXO content management system

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2

IGNORE_WITH_PHP=	71 72 73

NO_BUILD=	yes

SUB_FILES+=	pkg-message pkg-deinstall

USE_PHP=	mysql session xml zlib
USES=		cpe zip:infozip

OPTIONS_DEFINE=	APACHE MYSQLS GD

APACHE_DESC=	Use Apache as http server
MYSQLS_DESC=	Use MySQL database server
GD_DESC=	Enable Image Manager extension (requires gd)

OPTIONS_DEFAULT=	APACHE MYSQLS GD

MYSQLS_USES=	mysql:server

APACHE_USES=	php:mod
APACHE_USES_OFF=	php

GD_USE=	PHP=gd

do-extract:
	@${INSTALL} -d ${WRKDIR}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DISTFILES} -d ${WRKSRC}

do-install:
	cd ${WRKSRC} && \
	${FIND} . | \
	${CPIO} --quiet -pdm ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

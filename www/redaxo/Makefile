# Created by: Marco Steinbach <coco@executive-computing.de>
# $FreeBSD$

PORTNAME=	redaxo
PORTVERSION=	4.5
CATEGORIES=	www
MASTER_SITES=	http://www.redaxo.org/files/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}

MAINTAINER=	coco@executive-computing.de
COMMENT=	The REDAXO content management system

LICENSE=	GPLv2

NO_BUILD=	yes
SUB_FILES+=	pkg-message pkg-deinstall
USE_PHP=	mysql session xml zlib
USE_ZIP=	yes

OPTIONS_DEFINE=	APACHE MYSQLS GD

APACHE_DESC=	Use Apache (2.2) as http server
MYSQLS_DESC=	Use MySQL database server
GD_DESC=	Enable Image Manager extension (requires gd)

OPTIONS_DEFAULT=	APACHE MYSQLS GD

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQLS}
USE_MYSQL=	server
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

do-extract:
	@${INSTALL} -d ${WRKDIR}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DISTFILES} -d ${WRKSRC}

do-install:
	cd ${WRKSRC} && \
	${FIND} . | \
	${CPIO} --quiet -pdm -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>

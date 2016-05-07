# $FreeBSD$

PORTNAME=	ganglia
PORTVERSION=	3.7.1
CATEGORIES=	sysutils net parallel www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-web/${PORTVERSION}
PKGNAMESUFFIX=	-webfrontend
DISTNAME=	${PORTNAME}-web-${PORTVERSION}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Ganglia cluster monitor, web frontend

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/sbin/gmetad:sysutils/ganglia-monitor-core

USE_PHP=	filter gd xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

WWWDIR=		${PREFIX}/www/ganglia

SUB_FILES+=	pkg-message
SUB_LIST+=	WWWDIR="${WWWDIR}"

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

REINPLACE_ARGS=	-i ''
CONFIG_FILES=	default.json event_color.json events.json view_default.json

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@vargwebstatedir@|${DATADIR}|' \
			  -e 's|@vargmetadir@|/var/db/ganglia|' \
			  -e 's|/usr/bin/rrdtool|${LOCALBASE}/bin/rrdtool|' \
			  ${WRKSRC}/conf_default.php.in
	@${REINPLACE_CMD} -e 's|@GWEB_VERSION@|${PORTVERSION}|' \
			  ${WRKSRC}/version.php.in
	@${CP} ${WRKSRC}/version.php.in ${WRKSRC}/version.php
	@${CP} ${WRKSRC}/conf_default.php.in ${WRKSRC}/conf_default.php

do-install:
	@cd ${WRKSRC} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! ( -name *\.in -o -name .gitignore -o -name Makefile -o -name apache.conf.in -o -name apache.conf -o -name conf -o -path \./conf/* -o -name debian -o -path \./debian/* -o -name ganglia-web\.spec )"
	@${MKDIR} ${STAGEDIR}${DATADIR}/conf/sql
	@${MKDIR} ${STAGEDIR}${DATADIR}/dwoo/cache
	@${MKDIR} ${STAGEDIR}${DATADIR}/dwoo/compiled

.for file in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${file} ${STAGEDIR}${DATADIR}/conf/${file}.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/conf/sql/* ${STAGEDIR}${DATADIR}/conf/sql/

.include <bsd.port.mk>

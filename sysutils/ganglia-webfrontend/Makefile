PORTNAME=	ganglia
PORTVERSION=	3.7.2
PORTREVISION=	3
CATEGORIES=	sysutils net parallel www
PKGNAMESUFFIX=	-webfrontend${PHP_PKGNAMESUFFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ganglia cluster monitor, web frontend

LICENSE=	BSD3CLAUSE

DEPRECATED=Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

IGNORE_WITH_PHP=	80 81

RUN_DEPENDS=	${LOCALBASE}/sbin/gmond:sysutils/ganglia-monitor-core

USES=		cpe php:flavors,web
CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	${PORTNAME}-web
USE_GITHUB=	yes
GH_PROJECT=	ganglia-web
USE_PHP=	filter gd session xml

NO_ARCH=	yes
NO_BUILD=	yes

WWWDIR=		${PREFIX}/www/ganglia

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}" WWWDIR="${WWWDIR}"
SUB_FILES+=	pkg-message

REINPLACE_ARGS=	-i ''
CONFIG_FILES=	default.json event_color.json events.json view_default.json

post-patch:
	@${REINPLACE_CMD} -e 's|@vargwebstatedir@|${DATADIR}|' \
			  -e 's|@vargmetadir@|/var/db/ganglia|' \
			  -e 's|/usr/bin/rrdtool|${LOCALBASE}/bin/rrdtool|' \
		${WRKSRC}/conf_default.php.in
	@${REINPLACE_CMD} -e 's|@GWEB_VERSION@|${PORTVERSION}|' \
		${WRKSRC}/version.php.in

do-install:
	@${CP} ${WRKSRC}/conf_default.php.in ${WRKSRC}/conf_default.php
	@${CP} ${WRKSRC}/version.php.in      ${WRKSRC}/version.php
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! ( -name .git -o -name \.gitignore -o -name \.travis.yml -o \
		-name AUTHORS -o -name COPYING -o -name Makefile -o -name \
		README -o -name TODO -o -name *\.in -o -name conf -o -path \
		\./conf/* -o -name debian -o -path \./debian/* -o -name \
		ganglia-web\.spec )")
	@${MKDIR} ${STAGEDIR}${DATADIR}/conf/sql
	@${MKDIR} ${STAGEDIR}${DATADIR}/dwoo/cache
	@${MKDIR} ${STAGEDIR}${DATADIR}/dwoo/compiled

.for file in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${file} ${STAGEDIR}${DATADIR}/conf/${file}.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/conf/sql/* ${STAGEDIR}${DATADIR}/conf/sql/

.include <bsd.port.mk>

# Created by: Chris St Denis <chris@smartt.com>
# $FreeBSD$

PORTNAME=	nagiosql
PORTVERSION=	3.4.1
CATEGORIES=	net-mgmt www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Web based administration tool for Nagios

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nagios:net-mgmt/nagios \
		${PEARDIR}/HTML/Template/IT.php:devel/pear-HTML_Template_IT@${PHP_FLAVOR}

USES=		cpe gettext mysql php:web tar:bzip2
USE_PHP=	filter gettext mysqli session simplexml

USE_GITLAB=	yes
GL_ACCOUNT=	wizonet
GL_COMMIT=	365d4e0b5edc623b12ea96e8002e8ac66aad6aac

USERS?=		nagios
GROUPS?=	nagios
NAGIOSUSER?=	nagios

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${GL_COMMIT}-${GL_COMMIT}

SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} NAGIOSUSER=${NAGIOSUSER}

PEARDIR?=	${LOCALBASE}/share/pear

OPTIONS_DEFINE=	CURL FTP
CURL_DESC=	Configure with cURL support
FTP_DESC=	Configure with FTP support

CURL_USE=	PHP=curl
FTP_USE=	PHP=ftp

post-patch:
	${REINPLACE_CMD} -e "s|'/etc/nagiosql/|'${ETCDIR}/|g" \
		-e "s|/opt/nagios/etc/objects/|${LOCALBASE}/etc/nagios/objects/|" \
		-e "s|/opt/nagios/bin/nagios|${LOCALBASE}/bin/nagios|" \
		-e "s|/var/nagios/nagios.lock|/var/spool/nagios/nagios.lock|" \
		-e "s|/var/nagios/rw/nagios.cmd|/var/spool/nagios/rw/nagios.cmd|" \
		-e "s|nagios/etc/|etc/nagios/|" \
		-e "s|nagiosql/etc/|${ETCDIR}/|" \
		-e "s|>/etc/nagiosql|>${ETCDIR}|g" \
		-e "s|>/etc/nagios/|>${LOCALBASE}/etc/nagios/|g" \
		${WRKSRC}/install/sql/nagiosQL_v32_db_mysql.sql

	${REINPLACE_CMD} -e "s|\"/etc/|\"${LOCALBASE}/etc/|" \
		${WRKSRC}/install/install.php

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/ssh
	@${MKDIR} ${STAGEDIR}${ETCDIR}/hosts
	@${MKDIR} ${STAGEDIR}${ETCDIR}/services
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup/hosts
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup/services
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup/ssh
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! ( -name *\.orig -o -name *\.bak )")

.include <bsd.port.mk>

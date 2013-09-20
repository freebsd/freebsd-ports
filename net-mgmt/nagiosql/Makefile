# Created by: Chris St Denis <chris@smartt.com>
# $FreeBSD$

PORTNAME=	nagiosql
PORTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NagiosQL%20${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//g}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}_SP2

MAINTAINER=	chris@smartt.com
COMMENT=	A web based administration tool for Nagios

LICENSE=	GPLv2

RUN_DEPENDS=	nagios:${PORTSDIR}/net-mgmt/nagios \
		${PEARDIR}/HTML/Template/IT.php:${PORTSDIR}/devel/pear-HTML_Template_IT

USE_BZIP2=	yes
USE_MYSQL=	yes
USES=		gettext
USE_PHP=	mysql filter gettext session simplexml
WANT_PHP_WEB=	yes

USERS?=		nagios
GROUPS?=	nagios
NAGIOSUSER?=	nagios

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}32

SUB_FILES=	pkg-message pkg-install
SUB_LIST=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} NAGIOSUSER=${NAGIOSUSER}

PEARDIR?=	${LOCALBASE}/share/pear

OPTIONS_DEFINE=	CURL FTP SSH2
CURL_DESC=	Configure with cURL support
FTP_DESC=	Configure with FTP support
SSH2_DESC=	Configure with SSH2 support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MFTP}
USE_PHP+=	ftp
.endif

.if ${PORT_OPTIONS:MSSH2}
USE_PHP+=	ssh2
.endif

post-patch:
	${REINPLACE_CMD} -e "s|\'/etc/nagiosql/|\'${ETCDIR}/|g" \
		-e "s|/opt/nagios/etc/objects/|${LOCALBASE}/etc/nagios/objects/|" \
		-e "s|/opt/nagios/bin/nagios|${LOCALBASE}/bin/nagios|" \
		-e "s|/var/nagios/nagios.lock|/var/spool/nagios/nagios.lock|" \
		-e "s|/var/nagios/rw/nagios.cmd|/var/spool/nagios/rw/nagios.cmd|" \
		-e "s|nagios/etc/|etc/nagios/|" \
		-e "s|nagiosql/etc/|${ETCDIR}/|" \
		-e "s|\>/etc/nagiosql|\>${ETCDIR}|g" \
		-e "s|\>/etc/nagios/|\>${LOCALBASE}/etc/nagios/|g" \
		${WRKSRC}/install/sql/nagiosQL_v32_db_mysql.sql

	${REINPLACE_CMD} -e "s|\"/etc/|\"${LOCALBASE}/etc/|" \
		${WRKSRC}/install/install.php

do-install:
	@${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR} "! ( -name *\.orig -o -name *\.bak )")
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/config

post-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

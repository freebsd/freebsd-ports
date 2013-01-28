# Created by: rflynn@acsalaska.net
# $FreeBSD$
# $Redports: melflynn/net-mgmt/observium/Makefile 2134 2012-02-21 13:14:38Z melflynn $

PORTNAME=	observium
PORTVERSION=	0.11.5.2261
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://observium.org/ \
		http://cpansearch.perl.org/src/BBB/Net-Ping-2.31/demo/
DISTNAME=	${PORTNAME}-latest
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # prevent being 'fping' with JAIL
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An autodiscovering PHP/MySQL/SNMP based network monitoring

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	snmp ctype gd mysql session xml
WANT_PHP_CLI=	yes

RUN_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool \
		dot:${PORTSDIR}/graphics/graphviz \
		Magick-config:${PORTSDIR}/graphics/ImageMagick \
		mtr:${PORTSDIR}/net/mtr-nox11 \
		${LOCALBASE}/share/pear/Net/IPv4.php:${PORTSDIR}/net/pear-Net_IPv4 \
		${LOCALBASE}/share/pear/Net/IPv6.php:${PORTSDIR}/net/pear-Net_IPv6 \
		snmpget:${PORTSDIR}/net-mgmt/net-snmp

OPTIONS_DEFINE=	APACHEMOD MYSQLD JAIL
OPTIONS_DEFAULT=	APACHEMOD
APACHEMOD_DESC=	Use PHP with Apache 2.2+ module
MYSQLD_DESC=	Use local MySQL server
JAIL_DESC=	This is a jail installation

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message
SUB_LIST+=	PHP="${PHPBASE}/bin/php"

# :r!ls *.php *.sql
ROOT_FILES=	addhost.php adduser.php alerts.php check-errors.php \
		check-services.php delhost.php discovery.php \
		generate-iplist.php irc.php poll-billing.php \
		poll-device.php poller.php renamehost.php snmptrap.php \
		syslog.php database-schema.sql database-update-pre1000.sql \
		database-update-pre1435.sql database-update-pre2245.sql \
		database-update.sql config.php.default
ROOT_DIRS=	attic contrib html includes mibs scripts upgrade-scripts
PORTDOCS=	CHANGELOG INSTALL README
PORTEXAMPLES=	snmp.conf.example snmpd.conf.example

.if ${PORT_OPTIONS:MAPACHEMOD} && !defined(PACKAGE_BUILDING)
WANT_PHP_MOD=	yes
USE_APACHE=	22+
.else
# Package builder doesn't create php5 with module
WANT_PHP_WEB=	yes
.endif

.if ${PORT_OPTIONS:MMYSQLD}
USE_MYSQL=	server
.else
USE_MYSQL=	client
.endif

.if ${PORT_OPTIONS:MJAIL}
RUN_DEPENDS+=	p5-Net-Ping>=0:${PORTSDIR}/net/p5-Net-Ping
DISTFILES+=	fping
SUB_LIST+=	FPING="${LOCALBASE}/bin/fping-perl"
PLIST_SUB+=	JAIL=""
.else
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
SUB_LIST+=	FPING="${LOCALBASE}/sbin/fping"
PLIST_SUB+=	JAIL="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -name '.svn' -exec ${RM} -rf {} +
.if defined(WITH_JAIL)
	@${CP} ${DISTDIR}/fping ${WRKDIR}/fping
.endif

do-build:
.if ${PORT_OPTIONS:MJAIL}
	@${REINPLACE_CMD} -e 's,^#!.*$$,#!${PERL},' ${WRKDIR}/fping
.endif
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} \
		-e 's,#!/usr/bin/perl,#!${PERL},'
	@${REINPLACE_CMD} -E 's,<\?=([^?]+)\?>,<?php echo \1;?>,g' \
		${WRKSRC}/html/graph-realtime.php
	@${RM} ${WRKSRC}/html/includes/geshi/docs/COPYING
	@${RM} ${WRKSRC}/html/pages/addhost.inc.php.orig

do-install:
	@${MKDIR} ${WWWDIR}
	@${FIND} ${WRKSRC} -name '*.bak' -delete
.for dir in ${ROOT_DIRS}
	@${MKDIR} ${WWWDIR}/${dir}
	@${ECHO_MSG} "===>   Installing ${dir}"
	@cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${WWWDIR}/${dir}
.endfor
	@${ECHO_MSG} "===>   Installing root files"
.for f in ${ROOT_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${WWWDIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MJAIL}
	@${INSTALL_SCRIPT} ${WRKDIR}/fping ${PREFIX}/bin/fping-perl
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>

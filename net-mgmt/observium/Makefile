# Created by: rflynn@acsalaska.net
# $Redports: melflynn/net-mgmt/observium/Makefile 2134 2012-02-21 13:14:38Z melflynn $
# $FreeBSD$

PORTNAME=	observium
PORTVERSION=	0.11.5.2261
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://observium.org/ \
		http://cpansearch.perl.org/src/BBB/Net-Ping-2.31/demo/
DISTNAME=	${PORTNAME}-latest
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
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

OPTIONS=	APACHEMOD	"Use php with apache22+ module" On \
		MYSQLD		"Use local MySQL server" Off \
		JAIL		"This is a jail install" Off

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

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
WITHOUT_APACHEMOD=yes # Package builder doesn't create php5 with module
.endif

.if !defined(WITHOUT_APACHEMOD)
WANT_PHP_MOD=	yes
USE_APACHE=	22+
.else
WANT_PHP_WEB=	yes
.endif

.if !defined(WITHOUT_MYSQLD)
USE_MYSQL=	server
.else
USE_MYSQL=	client
.endif

.if defined(WITH_JAIL)
RUN_DEPENDS+=	p5-Net-Ping>=0:${PORTSDIR}/net/p5-Net-Ping
DISTFILES+=	fping
SUB_LIST+=	FPING="${LOCALBASE}/bin/fping-perl"
PLIST_FILES+=	bin/fping-perl
.else
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
SUB_LIST+=	FPING="${LOCALBASE}/sbin/fping"
.endif

post-extract:
	@${FIND} ${WRKSRC} -name '.svn' -exec ${RM} -rf {} +
.if defined(WITH_JAIL)
	@${CP} ${DISTDIR}/fping ${WRKDIR}/fping
.endif

do-build:
.if defined(WITH_JAIL)
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
.for file in ${ROOT_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${WWWDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif
.if defined(WITH_JAIL)
	@${INSTALL_SCRIPT} ${WRKDIR}/fping ${PREFIX}/bin/fping-perl
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>

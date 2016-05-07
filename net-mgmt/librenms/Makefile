# Created by: Muhammad Moinur Rahman<bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librenms
PORTVERSION=	201604
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.librenms.org/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	librenms

USES=		python shebangfix
SHEBANG_FILES=	html/js/makemini.pl mibs/process.pl scripts/agent-local/bind \
		scripts/agent-local/dmi scripts/agent-local/dpkg \
		scripts/agent-local/drbd scripts/agent-local/hddtemp \
		scripts/agent-local/memcached scripts/agent-local/mysql \
		scripts/agent-local/rpm scripts/agent-local/temperature \
		scripts/agent-local/tinydns scripts/apache-stats.py \
		scripts/check_mk_agent scripts/cron.sh scripts/cron-hourly.sh \
		scripts/cron-minute.sh scripts/get-geshi.sh \
		scripts/get-jpgraph.sh scripts/ifAlias \
		scripts/Migration/Standard_Conversion/convert_no_xml.sh \
		scripts/Migration/Standard_Conversion/destwork_no_xml.sh \
		scripts/Migration/Standard_Conversion/mkdir.sh \
		scripts/Migration/XML_Conversion/convert.sh \
		scripts/Migration/XML_Conversion/destwork.sh \
		scripts/Migration/XML_Conversion/mkdir.sh validate.php \
		scripts/postfix-queues scripts/removespikes.php \
		scripts/removespikes.pl scripts/watchmaillog/watchmaillog.pl
USE_PHP=	ctype filter gd json mcrypt mysql session snmp tokenizer xml
WANT_PHP_CLI=	yes

NO_BUILD=	yes

RUN_DEPENDS+=	rrdtool:databases/rrdtool \
		dot:graphics/graphviz \
		${LOCALBASE}/share/pear/Net/IPv4.php:net/pear-Net_IPv4 \
		${LOCALBASE}/share/pear/Net/IPv6.php:net/pear-Net_IPv6 \
		snmpget:net-mgmt/net-snmp \
		bash:shells/bash

OPTIONS_DEFINE=	APACHEMOD FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS NMAP PYPOLLER WMIC DOCS EXAMPLES X11
OPTIONS_DEFAULT=	APACHEMOD FPING IPMITOOL LIBVIRT NAGPLUGINS NMAP PYPOLLER WMIC DOCS EXAMPLES
APACHEMOD_DESC=	Use PHP with Apache 2.2+ module
FPING_DESC=	Enable fping support ping monitoring
IPMITOOL_DESC=	Enable support for monitoring hardware IPMI
MYSQLD_DESC=	Use local MySQL server
WMIC_DESC=	Enable support for WMI polling
PYPOLLER_DESC=	Enable Python Poller Wrapper

FPING_RUN_DEPENDS=	fping:net/fping
IPMITOOL_RUN_DEPENDS=	ipmitool:sysutils/ipmitool
LIBVIRT_RUN_DEPENDS=	virsh:devel/libvirt
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins
NMAP_RUN_DEPENDS=	nmap:security/nmap
PYPOLLER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>0:databases/py-MySQLdb
X11_RUN_DEPENDS=	Magick-config:graphics/ImageMagick \
			mtr:net/mtr
X11_RUN_DEPENDS_OFF=	Magick-config:graphics/ImageMagick-nox11 \
			mtr:net/mtr-nox11

WMIC_RUN_DEPENDS=	wmic:net-mgmt/wmi-client
MYSQLD_USE=		MYSQL=server
MYSQLD_USE_OFF=		MYSQL=client

SUB_FILES+=	pkg-message
SUB_LIST+=	PHP="${PHPBASE}/bin/php" PYTHON=${PYTHON_CMD}

ROOT_FILES=	addhost.php adduser.php	alerts.php build-base.php build.sql \
		billing-calculate.php \
		check-services.php config_to_json.php daily.php daily.sh \
		delhost.php discovery.php dist-pollers.php irc.php \
		poll-billing.php poller.php poller-service.py poller-wrapper.py renamehost.php \
		snmp-scan.php snmptrap.php syslog.php validate.php

ROOT_DIRS=	contrib html includes lib mibs scripts sql-schema

DOCS=		AUTHORS.md CHANGELOG CONTRIBUTING.md LICENSE.txt README.md
PORTDOCS=	*
PORTEXAMPLES=	snmp.conf.example snmpd.conf.example
NO_ARCH=	yes

.if !defined(PACKAGE_BUILDING)
APACHEMOD_VARS_ON=	WANT_PHP_MOD=yes
APACHEMOD_USE=		APACHE_RUN=22+
.else
# Package builder doesn't create php5 with module
WANT_PHP_WEB=	yes
.endif

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	       ${WRKSRC}/poller-wrapper.py ${WRKSRC}/poller.php

do-install:
	@${MKDIR} ${STAGEDIR}/${WWWDIR}
.for dir in ${ROOT_DIRS}
	@${MKDIR} ${STAGEDIR}/${WWWDIR}/${dir}
	@cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/${dir}
.endfor
.for f in ${ROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
# Create empty rrd dir writable by www
	@${MKDIR} ${STAGEDIR}/${WWWDIR}/rrd
# Files in scripts dir should be executable
	@${FIND} ${STAGEDIR}/${WWWDIR}/scripts -type f -exec ${CHMOD} +x {} \;
# Ensure PHP and Python scripts are executable
	@${FIND} ${STAGEDIR}/${WWWDIR} -type f -name '*.py' -or -type f -name \
	       '*.php' -exec ${CHMOD} +x {} \;

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}/${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

post-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${INSTALL_DATA} ${WRKSRC}/config.php.default \
	       ${STAGEDIR}/${WWWDIR}/config.php.sample
	@${ECHO} @sample ${WWWDIR}/config.php.sample >> ${TMPPLIST}
	@${ECHO} @dir ${WWWDIR}/rrd >> ${TMPPLIST}
	@${ECHO} @dir ${WWWDIR}/lib/influxdb-php/vendor/guzzlehttp/guzzle/build >> ${TMPPLIST}
	@${ECHO} @dir ${WWWDIR}/lib/influxdb-php/vendor/guzzlehttp/guzzle/docs >> ${TMPPLIST}
	@${ECHO} @dir ${WWWDIR}/lib/influxdb-php/vendor/guzzlehttp/guzzle/tests >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}

.include <bsd.port.mk>

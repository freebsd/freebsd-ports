# Created by: Muhammad Moinur Rahman<bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librenms
PORTVERSION=	1.33.01
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	librenms

USES=		php:cli python shebangfix
SHEBANG_FILES=	scripts/auth_test.php scripts/deploy-docs.sh scripts/github-remove \
		scripts/Migration/Standard_Conversion/convert_no_xml.sh \
		scripts/Migration/Standard_Conversion/destwork_no_xml.sh \
		scripts/Migration/Standard_Conversion/mkdir.sh \
		scripts/Migration/XML_Conversion/convert.sh \
		scripts/Migration/XML_Conversion/destwork.sh \
		scripts/Migration/XML_Conversion/mkdir.sh \
		scripts/removespikes.php scripts/agent-local/nfs-stats.sh \
		scripts/removespikes.pl scripts/watchmaillog/watchmaillog.pl \
		vendor/ezyang/htmlpurifier/maintenance/add-vimline.php \
		vendor/ezyang/htmlpurifier/maintenance/config-scanner.php \
		vendor/ezyang/htmlpurifier/maintenance/flush-definition-cache.php \
		vendor/ezyang/htmlpurifier/maintenance/flush.php \
		vendor/ezyang/htmlpurifier/maintenance/generate-entity-file.php \
		vendor/ezyang/htmlpurifier/maintenance/generate-includes.php \
		vendor/ezyang/htmlpurifier/maintenance/generate-schema-cache.php \
		vendor/ezyang/htmlpurifier/maintenance/generate-standalone.php \
		vendor/ezyang/htmlpurifier/maintenance/merge-library.php \
		vendor/ezyang/htmlpurifier/maintenance/old-extract-schema.php \
		vendor/ezyang/htmlpurifier/maintenance/old-remove-require-once.php \
		vendor/ezyang/htmlpurifier/maintenance/old-remove-schema-def.php \
		vendor/ezyang/htmlpurifier/maintenance/rename-config.php \
		vendor/ezyang/htmlpurifier/maintenance/remove-trailing-whitespace.php \
		vendor/ezyang/htmlpurifier/maintenance/update-config.php \
		vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php

USE_PHP=	ctype curl filter gd hash json ldap mcrypt mysqli openssl session simplexml snmp tokenizer xml

NO_BUILD=	yes

RUN_DEPENDS+=	rrdtool:databases/rrdtool \
		dot:graphics/graphviz \
		${LOCALBASE}/share/pear/Net/IPv4.php:net/pear-Net_IPv4 \
		${LOCALBASE}/share/pear/Net/IPv6.php:net/pear-Net_IPv6 \
		snmpget:net-mgmt/net-snmp \
		bash:shells/bash \
		sudo:security/sudo

OPTIONS_DEFINE=	APACHEMOD FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS NMAP PYPOLLER WMIC DOCS EXAMPLES X11
OPTIONS_DEFAULT=	APACHEMOD FPING IPMITOOL LIBVIRT NAGPLUGINS NMAP PYPOLLER WMIC
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
PYPOLLER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:databases/py-MySQLdb
X11_RUN_DEPENDS=	Magick-config:graphics/ImageMagick \
			mtr:net/mtr
X11_RUN_DEPENDS_OFF=	Magick-config:graphics/ImageMagick-nox11 \
			mtr:net/mtr-nox11

WMIC_RUN_DEPENDS=	wmic:net-mgmt/wmi-client
MYSQLD_USES=		mysql:server
MYSQLD_USES_OFF=	mysql:client

SUB_FILES+=	pkg-message
SUB_LIST+=	PHP="${PHPBASE}/bin/php" PYTHON=${PYTHON_CMD}

ROOT_FILES=	addhost.php adduser.php	alerts.php build-base.php build.sql \
		billing-calculate.php \
		check-services.php composer.json config_to_json.php cronic daily.php daily.sh \
		delhost.php discovery-wrapper.py discovery.php dist-pollers.php irc.php \
		mkdocs.yml pbin.sh phpunit.xml poll-billing.php poller.php poller-service.py \
		poller-wrapper.py readmegen.yml renamehost.php services-wrapper.py \
		snmptrap.php syslog.php validate.php

ROOT_DIRS=	LibreNMS contrib doc html includes lib mibs misc scripts sql-schema tests vendor

DOCS=		AUTHORS.md CHANGELOG CONTRIBUTING.md LICENSE.txt README.md
PORTDOCS=	*
PORTEXAMPLES=	snmp.conf.example snmpd.conf.example
NO_ARCH=	yes

.if !defined(PACKAGE_BUILDING)
APACHEMOD_VARS_ON=	WANT_PHP_MOD=yes
APACHEMOD_USE=		APACHE_RUN=22+
.else
# Package builder doesn't create php5 with module
USES+=		php:web
.endif

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	       ${WRKSRC}/poller-wrapper.py ${WRKSRC}/poller.php
	${REINPLACE_CMD} 's|%%PORTVERSION%%|${PORTVERSION}|g' \
	       ${WRKSRC}/includes/common.php

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
	@${CHMOD} 0775 ${STAGEDIR}/${WWWDIR}/rrd
# Create empty logs dir
	@${MKDIR} ${STAGEDIR}/${WWWDIR}/logs
# Make daily.sh executable
	@${CHMOD} 0755 ${STAGEDIR}/${WWWDIR}/daily.sh
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
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type d | \
		${SED} -e 's#^${STAGEDIR}#@dir #' >> ${TMPPLIST}
	${INSTALL_DATA} ${WRKSRC}/config.php.default \
	       ${STAGEDIR}/${WWWDIR}/config.php.sample
	@${ECHO} @sample ${WWWDIR}/config.php.sample >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}

.include <bsd.port.mk>

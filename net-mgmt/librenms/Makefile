PORTNAME=	librenms
PORTVERSION=	25.8.0
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	LOCAL/dvl:vendor
DISTFILES=	${PORTNAME}-vendor-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}:vendor

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring
WWW=		https://www.librenms.org

LICENSE=	GPLv3

# perhaps we also need python-memcache python-mysqldb
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>0:www/py-python-dotenv@${PY_FLAVOR} \
		bash:shells/bash \
		dot:graphics/graphviz \
		rrdtool:databases/rrdtool \
		snmpget:net-mgmt/net-snmp

USES=		cpe php python shebangfix
USE_GITHUB=	yes
# php hash/json/openssl extension is required but it's statically linked in default php
USE_PHP=	ctype curl dom fileinfo filter gd iconv ldap mbstring mysqli \
		pdo pdo_mysql phar posix session simplexml snmp sockets \
		tokenizer xml xmlwriter zip zlib
USE_RC_SUBR=	librenms

SHEBANG_FILES=	../${PORTNAME}-vendor-${PORTVERSION}/paragonie/random_compat/build-phar.sh \
		../${PORTNAME}-vendor-${PORTVERSION}/tecnickcom/tcpdf/tools/tcpdf_addfont.php \
		../librenms-vendor-${PORTVERSION}/bin/carbon \
		../librenms-vendor-${PORTVERSION}/bin/patch-type-declarations \
		../librenms-vendor-${PORTVERSION}/bin/php-parse \
		../librenms-vendor-${PORTVERSION}/bin/psysh \
		../librenms-vendor-${PORTVERSION}/bin/validate-json \
		../librenms-vendor-${PORTVERSION}/bin/var-dump-server \
		../librenms-vendor-${PORTVERSION}/bin/yaml-lint \
		../librenms-vendor-${PORTVERSION}/justinrainbow/json-schema/bin/validate-json \
		../librenms-vendor-${PORTVERSION}/nesbot/carbon/bin/carbon \
		../librenms-vendor-${PORTVERSION}/nikic/php-parser/bin/php-parse \
		../librenms-vendor-${PORTVERSION}/psy/psysh/bin/psysh \
		../librenms-vendor-${PORTVERSION}/symfony/error-handler/Resources/bin/extract-tentative-return-types.php \
		../librenms-vendor-${PORTVERSION}/symfony/error-handler/Resources/bin/patch-type-declarations \
		../librenms-vendor-${PORTVERSION}/symfony/var-dumper/Resources/bin/var-dump-server \
		../librenms-vendor-${PORTVERSION}/symfony/yaml/Resources/bin/yaml-lint \
		alerts.php artisan billing-calculate.php check-services.php \
		config_to_json.php cronic daily.php daily.sh delhost.php \
		discovery-wrapper.py discovery.php dist-pollers.php irc.php \
		librenms-service.py LibreNMS/command_runner.py \
		LibreNMS/wrapper.py lnms misc/lnms-completion.bash \
		misc/smokeping-debian.example misc/smokeping-rhel.example \
		ping.php poll-billing.php poller-wrapper.py poller.php \
		renamehost.php scripts/auth_test.php scripts/bash_lint.sh \
		scripts/check_requirements.py scripts/collect-port-polling.php \
		scripts/collect-snmp-data.php scripts/composer_wrapper.php \
		scripts/dynamic_check_requirements.py scripts/gen_rancid.php \
		scripts/gen_smokeping.php scripts/git-pre-commit-hook.sh \
		scripts/github-remove scripts/ifAlias scripts/json-app-tool.php \
		scripts/manage_bills.php \
		scripts/Migration/Standard_Conversion/convert_no_xml.sh \
		scripts/Migration/Standard_Conversion/destwork_no_xml.sh \
		scripts/Migration/Standard_Conversion/mkdir.sh \
		scripts/Migration/XML_Conversion/convert.sh \
		scripts/Migration/XML_Conversion/destwork.sh \
		scripts/Migration/XML_Conversion/mkdir.sh scripts/new-os.php \
		scripts/pre-commit.php scripts/purge-port.php \
		scripts/removespikes.php scripts/removespikes.pl \
		scripts/rename-mibs.php scripts/rrdstep.php \
		scripts/save-test-data.php scripts/syslog-notify-oxidized.php \
		scripts/test-alert.php scripts/test-template.php \
		scripts/watchmaillog/watchmaillog.pl snmp-scan.py snmptrap.php \
		syslog.php validate.php

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES+=	pkg-message
SUB_LIST+=	GROUP="${WWWGRP}" \
		PHP="${PHPBASE}/bin/php" \
		PYTHON=${PYTHON_CMD} \
		PYTHON_VERSION=${PYTHON_VERSION} \
		USER="${WWWOWN}" \
		WWWDIR="${WWWDIR}"

USERS=		www

PORTDOCS=	*
PORTEXAMPLES=	snmpd.conf.example

DBDIR=		/var/db/${PORTNAME}

OPTIONS_DEFINE=		DOCS EXAMPLES FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS \
			NMAP WMIC X11
OPTIONS_DEFAULT=	FPING IPMITOOL LIBVIRT NAGPLUGINS NMAP PYPOLLER SUDO \
			WMIC
OPTIONS_RADIO=		SUDO
OPTIONS_RADIO_SUDO=	SUDO SUDO_SSSD

SUDO_RUN_DEPENDS=	sudo:security/sudo
SUDO_SSSD_RUN_DEPENDS=	sudo:security/sudo@sssd

FPING_DESC=	Enable fping support ping monitoring
IPMITOOL_DESC=	Enable support for monitoring hardware IPMI
MYSQLD_DESC=	Use local MySQL server
WMIC_DESC=	Enable support for WMI polling
SUDO_DESC=	use security/sudo
SUDO_SSSD_DESC=	use security/sudo@sssd

FPING_RUN_DEPENDS=	fping:net/fping
IPMITOOL_RUN_DEPENDS=	ipmitool:sysutils/ipmitool
LIBVIRT_RUN_DEPENDS=	virsh:devel/libvirt
MYSQLD_USES=		mysql:server
MYSQLD_USES_OFF=	mysql:client
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins
NMAP_RUN_DEPENDS=	nmap:security/nmap
WMIC_RUN_DEPENDS=	wmic:net-mgmt/wmi-client
X11_RUN_DEPENDS=	mtr:net/mtr
X11_RUN_DEPENDS_OFF=	mtr:net/mtr@nox11
X11_USES=		magick:6
X11_USES_OFF=		magick:6,nox11

_ROOT_FILES=		alerts.php artisan billing-calculate.php \
			check-services.php composer.json composer.lock \
			config.php.default config_to_json.php cronic daily.php \
			delhost.php discovery-wrapper.py discovery.php \
			dist-pollers.php irc.php librenms-service.py mkdocs.yml \
			phpunit.xml ping.php poll-billing.php poller.php \
			poller-wrapper.py renamehost.php snmp-scan.py \
			snmptrap.php syslog.php validate.php
_SCRIPT_FILES=		daily.sh lnms
# _RELEASE_TIMESTAMP is used for a patch inside the vendor code
# it represents the release date via: git show --pretty='%H|%ct' -s 1.42.01
# It sits here so you remember to update it with each release
_RELEASE_TIMESTAMP=	1755492731
_ROOT_DIRS=		LibreNMS app bootstrap config database doc html \
			includes lang licenses mibs misc resources routes \
			scripts tests
_DOCS=			AUTHORS.md CHANGELOG.md CONTRIBUTING.md LICENSE.txt \
			README.md

# these are directories which require a generic @DIR entry in pkg-plist
_STORAGE_DIRS=	app app/public debugbar framework framework/cache \
		framework/cache/data framework/sessions framework/testing \
		framework/views logs
# these are directories which require a generic @DIR entry in pkg-plist
_OTHER_DIRS=	database/seeders/config html/plugins html/js/lang \
		resources/views/overview/custom tests/Browser/console \
		tests/Browser/source tests/Browser/screenshots \
		vendor/librenms/laravel-vue-i18n-generator/tests/output \
		vendor/symfony/mime/Resources/bin \
		vendor/symfony/string/Resources/bin

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/LibreNMS/__init__.py \
		${WRKSRC}/LibreNMS/wrapper.py \
		${WRKSRC}/LibreNMS/Util/Version.php \
		${WRKSRC}/LibreNMS/Validations/Php.php \
		${WRKSRC}/LibreNMS/Validations/System.php \
		${WRKSRC}/config.php.default \
		${WRKSRC}/includes/html/output/capture.inc.php \
		${WRKSRC}/poller-wrapper.py \
		${WRKSRC}/snmp-scan.py \
		${WRKSRC}/daily.sh
	${REINPLACE_CMD} 's|%%PORTVERSION%%|${PORTVERSION}|g'              ${WRKSRC}/LibreNMS/Util/Version.php
	${REINPLACE_CMD} 's|%%RELEASE_TIMESTAMP%%|${_RELEASE_TIMESTAMP}|g' ${WRKSRC}/LibreNMS/Util/Version.php
	${REINPLACE_CMD} 's|%%WWWDIR%%|${WWWDIR}|g'                        ${WRKSRC}/dist/librenms-scheduler.cron
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g'                  ${WRKSRC}/dist/librenms-scheduler.cron
	${REINPLACE_CMD} 's|%%USER%%|${WWWOWN}|g'                          ${WRKSRC}/dist/librenms-scheduler.cron
	${RM} ${WRKSRC}/LibreNMS/Validations/Updates.php
	${RM} -rf ${WRKSRC}/logs

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
.for dir in ${_ROOT_DIRS}
	${MKDIR} ${STAGEDIR}/${WWWDIR}/${dir}
	(cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/${dir})
.endfor
.for f in ${_ROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
.for f in ${_SCRIPT_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
# avoid: Error: lnms file is owned by root, it should be owned and ran by a non-privileged user
	${ECHO_CMD} "@(www,wheel,0555) www/${PORTNAME}/lnms" >> ${TMPPLIST}

	${MKDIR} ${STAGEDIR}/${WWWDIR}/vendor
	(cd ${WRKDIR}/${PORTNAME}-vendor-${PORTVERSION} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/vendor)

# As of 1.66_1, the package installs bootstrap/cache
# This was previously left to the code to populate.
# That causese problems when the code doesn't do that update.
	${MV} ${STAGEDIR}/${WWWDIR}/vendor/bootstrap-cache/* ${STAGEDIR}/${WWWDIR}/bootstrap/cache/
	${RM} -rf ${STAGEDIR}/${WWWDIR}/vendor/bootstrap-cache

# similarly with html/js/lang
	${MV} ${STAGEDIR}/${WWWDIR}/vendor/html-js-lang/* ${STAGEDIR}/${WWWDIR}/html/js/lang/
	${RM} -rf ${STAGEDIR}/${WWWDIR}/vendor/html-js-lang

# Files in scripts dir should be executable
	${FIND} ${STAGEDIR}/${WWWDIR}/scripts -type f -exec ${CHMOD} +x {} \;
# Ensure PHP and Python scripts are executable
	${FIND} ${STAGEDIR}/${WWWDIR} -type f -name '*.py' -or -type f -name \
	       '*.php' -exec ${CHMOD} +x {} \;
# these values should be outside the www tree now
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DBDIR}
	${MKDIR} ${STAGEDIR}${DBDIR}/storage
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	(cd ${STAGEDIR}/${WWWDIR} && ${LN} -s ../../../..${DBDIR}/storage)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}/${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -type f '(' -name '*.orig' -or -name '*.bak' -or -name '.gitignore' ')' -delete
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | grep -v www/librenms/lnms >> ${TMPPLIST}

# we do this file separately because it needs a different chmod/chown
# it will eventually contains secrets
	${INSTALL_DATA} ${WRKSRC}/.env.example ${STAGEDIR}/${WWWDIR}
	${ECHO_CMD} "@dir(www,www,0775) ${DBDIR}/storage" >> ${TMPPLIST}
	${ECHO_CMD} "@dir(www,www,0775) ${DBDIR}" >> ${TMPPLIST}
	${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/html/images/custommap/background" >> ${TMPPLIST}
	${ECHO_CMD} "@dir(www,www,0775) /var/log/${PORTNAME}" >> ${TMPPLIST}
	${ECHO_CMD} "@(root,www,0750) ${WWWDIR}/.env.example" >> ${TMPPLIST}

	${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/bootstrap/cache" >> ${TMPPLIST}
	${ECHO_CMD} "@dir(www,www,0775) /var/run/${PORTNAME}" >> ${TMPPLIST}
.for f in ${_STORAGE_DIRS}
	${MKDIR} ${STAGEDIR}/${DBDIR}/storage/${f}
	${ECHO_CMD} "@dir(root,www,0775) ${DBDIR}/storage/${f}" >> ${TMPPLIST}
.endfor
.for f in ${_OTHER_DIRS}
	${ECHO_CMD} "@dir(root,www,0775) ${WWWDIR}/${f}" >> ${TMPPLIST}
.endfor

	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf.sample ${STAGEDIR}/${PREFIX}/etc/newsyslog.conf.d/librenms.conf.sample
	${ECHO_CMD} "@dir etc/newsyslog.conf.d" >> ${TMPPLIST}
	${ECHO_CMD} "@sample etc/newsyslog.conf.d/librenms.conf.sample" >> ${TMPPLIST}

	${MKDIR} ${STAGEDIR}/${WWWDIR} ${STAGEDIR}${PREFIX}/etc/cron.d/
	${INSTALL_DATA} ${WRKSRC}/dist/librenms-scheduler.cron ${STAGEDIR}${PREFIX}/etc/cron.d/librenms
	${ECHO_CMD} "@dir etc/cron.d" >> ${TMPPLIST}
	${ECHO_CMD} "etc/cron.d/librenms" >> ${TMPPLIST}

# avoid the "Global lnms shortcut not installed." validataion warning.
# this can also be run as root.
	${RLN} ${STAGEDIR}${WWWDIR}/lnms ${STAGEDIR}${PREFIX}/bin/lnms
	${ECHO_CMD} "bin/lnms" >> ${TMPPLIST}

.include <bsd.port.mk>

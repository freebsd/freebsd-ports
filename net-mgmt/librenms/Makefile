# Created by: Muhammad Moinur Rahman<bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librenms
PORTVERSION=	1.70.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	LOCAL/dvl:vendor
DISTFILES=	${PORTNAME}-vendor-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}:vendor

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring

LICENSE=	GPLv3

USES=		shebangfix php:mod python

# RELEASE_TIMESTAMP is used for a patch inside the vendor code
# it represents the release date via: git show --pretty='%H|%ct' -s 1.42.01
# It sits here so you remember to update it with each release
RELEASE_TIMESTAMP=	1606919946

# perhaps we also need python-memcache python-mysqldb
RUN_DEPENDS+=	rrdtool:databases/rrdtool \
		dot:graphics/graphviz \
		${LOCALBASE}/share/pear/Net/IPv4.php:net/pear-Net_IPv4@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Net/IPv6.php:net/pear-Net_IPv6@${PHP_FLAVOR} \
		snmpget:net-mgmt/net-snmp \
		bash:shells/bash \
		sudo:security/sudo \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR}

USE_PHP=	ctype curl dom fileinfo filter gd hash json ldap mbstring \
		mysqli openssl pdo pdo_mysql phar posix session simplexml \
		snmp sockets tokenizer xml xmlwriter zip

USE_GITHUB=	yes
GH_ACCOUNT=	librenms

USE_RC_SUBR=	librenms

USERS=		www

NO_BUILD=	yes

OPTIONS_DEFINE=	FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS NMAP WMIC DOCS EXAMPLES X11
OPTIONS_DEFAULT=	FPING IPMITOOL LIBVIRT NAGPLUGINS NMAP PYPOLLER WMIC

FPING_DESC=	Enable fping support ping monitoring
IPMITOOL_DESC=	Enable support for monitoring hardware IPMI
MYSQLD_DESC=	Use local MySQL server
WMIC_DESC=	Enable support for WMI polling

FPING_RUN_DEPENDS=	fping:net/fping
IPMITOOL_RUN_DEPENDS=	ipmitool:sysutils/ipmitool
LIBVIRT_RUN_DEPENDS=	virsh:devel/libvirt
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins
NMAP_RUN_DEPENDS=	nmap:security/nmap
X11_RUN_DEPENDS=	Magick-config:graphics/ImageMagick6 \
			mtr:net/mtr
X11_RUN_DEPENDS_OFF=	Magick-config:graphics/ImageMagick6-nox11 \
			mtr:net/mtr-nox11

WMIC_RUN_DEPENDS=	wmic:net-mgmt/wmi-client
MYSQLD_USES=		mysql:server
MYSQLD_USES_OFF=	mysql:client

SHEBANG_FILES=	scripts/auth_test.php \
		scripts/check_requirements.py \
		scripts/deploy-docs.sh \
		scripts/github-remove \
		scripts/Migration/Standard_Conversion/convert_no_xml.sh \
		scripts/Migration/Standard_Conversion/destwork_no_xml.sh \
		scripts/Migration/Standard_Conversion/mkdir.sh \
		scripts/Migration/XML_Conversion/convert.sh \
		scripts/Migration/XML_Conversion/destwork.sh \
		scripts/Migration/XML_Conversion/mkdir.sh \
		scripts/removespikes.pl scripts/removespikes.php scripts/watchmaillog/watchmaillog.pl \
		poller.php poller-wrapper.py \
		../${PORTNAME}-vendor-${PORTVERSION}/swiftmailer/swiftmailer/lib/swiftmailer_generate_mimes_config.php \
		../${PORTNAME}-vendor-${PORTVERSION}/tecnickcom/tcpdf/tools/tcpdf_addfont.php

SUB_FILES+=	pkg-message
SUB_LIST+=	PHP="${PHPBASE}/bin/php" PYTHON=${PYTHON_CMD} \
		USER="${WWWOWN}" GROUP="${WWWGRP}" WWWDIR="${WWWDIR}"

ROOT_FILES=	addhost.php adduser.php alerts.php artisan billing-calculate.php \
		check-services.php composer.json \
		composer.lock config.php.default config_to_json.php cronic daily.php \
		delhost.php discovery-wrapper.py discovery.php dist-pollers.php irc.php \
		librenms-service.py mkdocs.yml pbin.sh phpunit.xml ping.php poll-billing.php poller.php \
		poller-wrapper.py renamehost.php snmp-scan.py \
		snmptrap.php syslog.php validate.php

SCRIPT_FILES=	daily.sh lnms

ROOT_DIRS=	LibreNMS app bootstrap config contrib database doc html includes licenses mibs misc resources routes scripts sql-schema storage tests

# these are directories which require a generic @DIR entry in pkg-plist
OTHER_DIRS=	html/js/lang \
		resources/views/overview/custom \
		storage/app/public \
		storage/debugbar \
		storage/framework/cache/data \
		storage/framework/testing \
		storage/logs \
		tests/Browser/console \
		tests/Browser/screenshots \
		vendor/librenms/laravel-vue-i18n-generator/tests/output \
		vendor/ramsey/collection/bin \
		vendor/symfony/string/Resources/bin

DOCS=		AUTHORS.md CHANGELOG.md CONTRIBUTING.md LICENSE.txt README.md
PORTDOCS=	*
PORTEXAMPLES=	snmpd.conf.example
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD}    's|%%PORTVERSION%%|${PORTVERSION}|g'             ${WRKSRC}/includes/common.php
	@${REINPLACE_CMD}    's|%%RELEASE_TIMESTAMP%%|${RELEASE_TIMESTAMP}|g' ${WRKSRC}/includes/common.php
	@${RM} ${WRKSRC}/LibreNMS/Validations/Updates.php
	@${RM} -rf ${WRKSRC}/logs

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
.for dir in ${ROOT_DIRS}
	${MKDIR} ${STAGEDIR}/${WWWDIR}/${dir}
	(cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/${dir})
.endfor
.for f in ${ROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
.for f in ${SCRIPT_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
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

# Make daily.sh executable
#	${CHMOD} 0755 ${STAGEDIR}/${WWWDIR}/daily.sh
# lnms does not fall into any other +x category
#	${CHMOD} 0755 ${STAGEDIR}/${WWWDIR}/lnms
# Files in scripts dir should be executable
	${FIND} ${STAGEDIR}/${WWWDIR}/scripts -type f -exec ${CHMOD} +x {} \;
# Ensure PHP and Python scripts are executable
	${FIND} ${STAGEDIR}/${WWWDIR} -type f -name '*.py' -or -type f -name \
	       '*.php' -exec ${CHMOD} +x {} \;
# these values should be outside the www tree now
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}/${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

post-install:
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type f '(' -name '*.orig' -or -name '*.bak' -or -name '.gitignore' ')' -delete
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

	# we do this file separately because it needs a different chmod/chown
	# it will eventually contains secrets
	${INSTALL_DATA} ${WRKSRC}/.env.example ${STAGEDIR}/${WWWDIR}
	@${ECHO_CMD} "@(root,www,0750) ${WWWDIR}/.env.example" >> ${TMPPLIST}

	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/bootstrap/cache" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/storage" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/storage/framework/cache" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/storage/framework/sessions" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/storage/framework/views" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) /var/log/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) /var/db/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) /var/run/${PORTNAME}" >> ${TMPPLIST}
.for f in ${OTHER_DIRS}
	@${ECHO_CMD} "@dir(root,www,0775) ${WWWDIR}/${f}" >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>

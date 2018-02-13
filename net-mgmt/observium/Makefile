# Created by: rflynn@acsalaska.net
# $FreeBSD$
# Observium version can be found by looking at ${WRKSRC}/includes/definitions/version.inc.php

PORTNAME=	observium
PORTVERSION=	0.17.9.8859
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.observium.org/
DISTNAME=	${PORTNAME}-community-latest
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring

LICENSE=	EULA
LICENSE_NAME=	"Observium License Version 1.0"
LICENSE_FILE=	${WRKSRC}/LICENSE.COMMUNITY
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		php:cli python${PY_MYSQL} shebangfix
SHEBANG_FILES=	\
		mibs/process.pl \
		poller-wrapper.py \
		poller.php \
		scripts/

USE_PHP=	ctype filter gd iconv json mcrypt mysqli openssl posix session snmp tokenizer xml zlib

NO_ARCH=	yes
NO_BUILD=	yes

RUN_DEPENDS+=	rrdtool:databases/rrdtool \
		dot:graphics/graphviz \
		mtr:net/mtr-nox11 \
		${LOCALBASE}/share/pear/Net/IPv4.php:net/pear-Net_IPv4 \
		${LOCALBASE}/share/pear/Net/IPv6.php:net/pear-Net_IPv6 \
		snmpget:net-mgmt/net-snmp \
		sudo:security/sudo
LIB_DEPENDS+=	libpng.so:graphics/png

OPTIONS_DEFINE=	APACHEMOD DOCS EXAMPLES FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS NMAP PYPOLLER SVN WMIC
OPTIONS_DEFAULT=	APACHEMOD FPING IPMITOOL LIBVIRT NAGPLUGINS NMAP PYPOLLER SVN WMIC
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
PYPOLLER_VARS=	PY_MYSQL=:2.7
SVN_RUN_DEPENDS=	svn:devel/subversion
WMIC_RUN_DEPENDS=	wmic:net-mgmt/wmi-client

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message observium.conf.sample
SUB_LIST+=	PHP="${PHPBASE}/bin/php" PYTHON=${PHPBASE}/bin/python

ROOT_FILES=	add_device.php adduser.php alerter.php alerts.php \
		check-errors.php check-services.php config_to_json.php \
		config.php.default delete_device.php discovery.php housekeeping.php \
		irc.php poller-wrapper.py poller.php rename_device.php \
		snmptrap.php snmptrap.php syslog.php test_alert.php
ROOT_DIRS=	html includes libs logs mibs rrd scripts templates tests update

PORTDOCS=	INSTALL README VERSION
PORTEXAMPLES=	snmp.conf.example snmpd.conf.example

.if ${PORT_OPTIONS:MAPACHEMOD}
USE_APACHE_RUN=	22+
.endif
.if !defined(PACKAGE_BUILDING)
USES+=	php:mod
.else
# Package builder doesn't create php5 with module
USES+=	php:web
.endif

.if ${PORT_OPTIONS:MMYSQLD}
USES+=	mysql:server
.else
USES+=	mysql:client
.endif

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/poller-wrapper.py ${WRKSRC}/poller.php
	${FIND} ${WRKSRC} -type d -empty -delete
	${MKDIR} ${WRKSRC}/logs ${WRKSRC}/rrd

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR} ${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes
	${INSTALL_DATA} ${WRKDIR}/observium.conf.sample ${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes
.for dir in ${ROOT_DIRS}
	${MKDIR} ${STAGEDIR}/${WWWDIR}/${dir}
	(cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/${dir})
.endfor
.for f in ${ROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
# Files in scripts dir should be executable
	${FIND} ${STAGEDIR}/${WWWDIR}/scripts -type f -exec ${CHMOD} +x {} \;
# Ensure PHP and Python scripts are executable
	${FIND} ${STAGEDIR}/${WWWDIR} -type f -name '*.py' -or -type f -name \
		'*.php' -exec ${CHMOD} +x {} \;

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

post-install:
	@${ECHO}  "@sample ${APACHEETCDIR}/Includes/observium.conf.sample" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type f '(' -name '*.orig' -or -name '*.bak' ')' -delete
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/logs" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/rrd" >> ${TMPPLIST}

.include <bsd.port.mk>

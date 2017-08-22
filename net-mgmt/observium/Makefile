# Created by: rflynn@acsalaska.net
# $FreeBSD$

PORTNAME=	observium
PORTVERSION=	0.16.10.8128
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.observium.org/
DISTNAME=	${PORTNAME}-community-latest
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	dirkx@webweaving.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring

LICENSE=        EULA
LICENSE_NAME=	"Observium License Version 1.0"
LICENSE_FILE=	${WRKSRC}/LICENSE.COMMUNITY
LICENSE_PERMS=  dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		php:cli python shebangfix
SHEBANG_FILES=	\
		mibs/process.pl \
		poller-wrapper.py \
		scripts/add_ds_to_rrd.pl \
		scripts/add_ds.pl \
		scripts/agent-local/areca-hw \
		scripts/agent-local/asterisk \
		scripts/agent-local/bind \
		scripts/agent-local/crashplan \
		scripts/agent-local/edac \
		scripts/agent-local/exim-mailqueue.sh \
		scripts/agent-local/hdarray \
		scripts/agent-local/ipmitool-sensor \
		scripts/agent-local/kamailio \
		scripts/agent-local/ksm \
		scripts/agent-local/lighttpd \
		scripts/agent-local/lmsensors \
		scripts/agent-local/lvs_stats \
		scripts/agent-local/memcached \
		scripts/agent-local/nginx \
		scripts/agent-local/postfix_mailgraph \
		scripts/agent-local/postfix_qshape \
		scripts/agent-local/postgresql.pl \
		scripts/agent-local/proxmox-qemu \
		scripts/agent-local/sabnzbd-qstatus \
		scripts/agent-local/temperature \
		scripts/agent-local/virt-what \
		scripts/agent-local/vmwaretools \
		scripts/agent-local/zimbra \
		scripts/get-geshi.sh \
		scripts/get-jpgraph.sh \
		scripts/glue.py \
		scripts/ifAlias \
		scripts/ifAlias_persist \
		scripts/logparser \
		scripts/makecss.sh \
		scripts/observium_agent \
		scripts/removespikes.php \
		scripts/removespikes.pl \
		scripts/rename-mibs.pl \
		scripts/rrdtoolx.py

USE_PHP=	ctype filter gd iconv json mcrypt mysqli openssl posix session snmp tokenizer xml zlib
IGNORE_WITH_PHP=	71

NO_BUILD=	yes

RUN_DEPENDS+=	rrdtool:databases/rrdtool \
		dot:graphics/graphviz \
		mtr:net/mtr-nox11 \
		${LOCALBASE}/share/pear/Net/IPv4.php:net/pear-Net_IPv4 \
		${LOCALBASE}/share/pear/Net/IPv6.php:net/pear-Net_IPv6 \
		snmpget:net-mgmt/net-snmp \
		sudo:security/sudo
LIB_DEPENDS+=	libpng.so:graphics/png

OPTIONS_DEFINE=	APACHEMOD FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS NMAP PYPOLLER SVN WMIC
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
SVN_RUN_DEPENDS=	svn:devel/subversion
WMIC_RUN_DEPENDS=	wmic:net-mgmt/wmi-client

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message observium.conf.sample
SUB_LIST+=	PHP="${PHPBASE}/bin/php" PYTHON=${PHPBASE}/bin/python

ROOT_FILES=	rename_device.php snmptrap.php add_device.php \
		snmpd.conf.example check-errors.php config_to_json.php delete_device.php \
		syslog.php irc.php snmp.conf.example adduser.php discovery.php \
		check-services.php poller.php config.php.default poller-wrapper.py
ROOT_DIRS=	html scripts includes update mibs libs

PORTDOCS=	INSTALL README
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

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR} ${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes
.for dir in ${ROOT_DIRS}
	${MKDIR} ${STAGEDIR}/${WWWDIR}/${dir}
	cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/${dir}
.endfor
.for f in ${ROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
	# Create empty rrd dir and logs writable by www (the apache user)
	${MKDIR} ${STAGEDIR}/${WWWDIR}/rrd ${STAGEDIR}/${WWWDIR}/logs
	# Files in scripts dir should be executable
	${FIND} ${STAGEDIR}/${WWWDIR}/scripts -type f -exec ${CHMOD} +x {} \;
	# Ensure PHP and Python scripts are executable
	${FIND} ${STAGEDIR}/${WWWDIR} -type f -name '*.py' -or -type f -name '*.php' -exec ${CHMOD} +x {} \;
	# Rename for @sample
	${MV} ${STAGEDIR}/${WWWDIR}/config.php.default ${STAGEDIR}/${WWWDIR}/config.php.default.sample

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKDIR}/observium.conf.sample ${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes

.include <bsd.port.mk>

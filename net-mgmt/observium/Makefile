PORTNAME=	observium
DISTVERSION=	24.12
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.observium.org/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}-community-${DISTVERSION}

MAINTAINER=	xaaports@dohd.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring
WWW=		https://observium.org

LICENSE=	EULA
LICENSE_NAME=	"Observium License Version 1.0"
LICENSE_FILE=	${WRKSRC}/LICENSE.COMMUNITY
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	rrdtool:databases/rrdtool \
		dot:graphics/graphviz \
		mtr:net/mtr@nox11 \
		${LOCALBASE}/share/pear/Net/IPv4.php:net/pear-Net_IPv4@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Net/IPv6.php:net/pear-Net_IPv6@${PHP_FLAVOR} \
		snmpget:net-mgmt/net-snmp \
		sudo:security/sudo

USES=		cpe php:cli,flavors python shebangfix
USE_PHP=	ctype filter gd iconv mysqli posix session snmp tokenizer xml zlib
IGNORE_WITH_PHP=	81
SHEBANG_FILES=	\
		poller-wrapper.py \
		poller.php \
		scripts/

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	APACHEMOD DOCS EXAMPLES FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS PYPOLLER SUBVERSION WMIC
OPTIONS_DEFAULT=	APACHEMOD FPING IPMITOOL LIBVIRT NAGPLUGINS PYPOLLER SUBVERSION WMIC
APACHEMOD_DESC=	Use PHP with Apache 2.4+ module
FPING_DESC=	Enable fping support ping monitoring
IPMITOOL_DESC=	Enable support for monitoring hardware IPMI
MYSQLD_DESC=	Use local MySQL server
PYPOLLER_DESC=	Enable Python Poller Wrapper
WMIC_DESC=	Enable support for WMI polling

FPING_RUN_DEPENDS=	fping:net/fping
IPMITOOL_RUN_DEPENDS=	ipmitool:sysutils/ipmitool
LIBVIRT_RUN_DEPENDS=	virsh:devel/libvirt
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins
PYPOLLER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=1.3.13:databases/py-mysqlclient@${PY_FLAVOR}
SUBVERSION_RUN_DEPENDS=	svn:devel/subversion
WMIC_RUN_DEPENDS=	wmic:net-mgmt/wmi-client

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message observium.conf.sample
SUB_LIST+=	PHP="${PREFIX}/bin/php" PYTHON="${PYTHON_CMD}"

ROOT_FILES=	add_device.php adduser.php alerter.php \
		config.php.default config_to_json.php \
		delete_device.php discovery.php housekeeping.php \
		irc.php notifications.php observium-wrapper poller-wrapper.py poller.php \
		rename_device.php snmp.conf.example snmpd.conf.example \
		snmptrap.php syslog.php test_alert.php test_code.php test_db.php test_geo.php VERSION
ROOT_DIRS=	html includes libs logs mibs rrd scripts templates tests update

PORTDOCS=	INSTALL README VERSION
PORTEXAMPLES=	snmp.conf.example snmpd.conf.example

.if ${PORT_OPTIONS:MAPACHEMOD}
USES+=	apache:run
.if !defined(PACKAGE_BUILDING)
USES+=	php:mod
.else
# Package builder doesn't create php8 with module
USES+=	php:web
.endif
.endif

.if ${PORT_OPTIONS:MMYSQLD}
USES+=	mysql:server
.else
USES+=	mysql:client
.endif

pre-install:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/poller-wrapper.py ${WRKSRC}/poller.php
	${FIND} ${WRKSRC} -type d -empty -delete
	${MKDIR} ${WRKSRC}/logs ${WRKSRC}/rrd

do-install:
.if ${PORT_OPTIONS:MAPACHEMOD}
	${MKDIR} ${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes
	${INSTALL_DATA} ${WRKDIR}/observium.conf.sample ${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes
.endif
	${MKDIR} ${STAGEDIR}/${WWWDIR}
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
.if ${PORT_OPTIONS:MAPACHEMOD}
	@${ECHO_CMD}  "@sample ${APACHEETCDIR}/Includes/observium.conf.sample" >> ${TMPPLIST}
.endif
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type f '(' -name '*.orig' -or -name '*.bak' ')' -delete
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/logs" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(www,www,0775) ${WWWDIR}/rrd" >> ${TMPPLIST}

.include <bsd.port.mk>

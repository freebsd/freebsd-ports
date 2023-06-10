PORTNAME=	nagiosql
PORTVERSION=	3.5.0.20230311
CATEGORIES=	net-mgmt www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Web based administration tool for Nagios
WWW=		https://gitlab.com/wizonet/nagiosql

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=	82 83

USES=		cpe gettext mysql php:web tar:bzip2
USE_PHP=	filter gettext mysqli session simplexml
USE_GITLAB=	yes
GL_ACCOUNT=	wizonet
GL_COMMIT=	7e40440fa5e0a4a81a3a40c2895b248bfabcdd84

USERS?=		nagios
GROUPS?=	nagios
NAGIOSUSER?=	nagios

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

PEARDIR?=	${LOCALBASE}/share/pear

OPTIONS_DEFINE=	CURL FTP NAGIOS4
CURL_DESC=	Configure with cURL support
FTP_DESC=	Configure with FTP support
NAGIOS4_DESC=	Configure with Nagios 4

CURL_USE=	PHP=curl
FTP_USE=	PHP=ftp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAGIOS4}
RUN_DEPENDS=	${PEARDIR}/HTML/Template/IT.php:devel/pear-HTML_Template_IT@${PHP_FLAVOR} \
		nagios:net-mgmt/nagios4
.else
RUN_DEPENDS=	${PEARDIR}/HTML/Template/IT.php:devel/pear-HTML_Template_IT@${PHP_FLAVOR} \
		nagios:net-mgmt/nagios
.endif

post-patch:
	${REINPLACE_CMD} -e "s|'/etc/nagiosql/|'${ETCDIR}/|g" \
		-e "s|/opt/nagios/etc/objects/|${LOCALBASE}/etc/nagios/objects/|" \
		-e "s|/opt/nagios/bin/nagios|${LOCALBASE}/bin/nagios|" \
		-e "s|/var/nagios/nagios.lock|/var/spool/nagios/nagios.lock|" \
		-e "s|/var/nagios/rw/nagios.cmd|/var/spool/nagios/rw/nagios.cmd|" \
		-e "s|nagios/etc/|etc/nagios/|" \
		-e "s|nagiosql/etc/|${ETCDIR}/|" \
		-e "s|>/etc/nagiosql|>${ETCDIR}|g" \
		-e "s|>/etc/nagios/|>${LOCALBASE}/etc/nagios/|g" \
		${WRKSRC}/install/sql/nagiosQL_v32_db_mysql.sql

	${REINPLACE_CMD} -e "s|\"/etc/|\"${LOCALBASE}/etc/|" \
		${WRKSRC}/install/install.php

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/ssh
	@${MKDIR} ${STAGEDIR}${ETCDIR}/hosts
	@${MKDIR} ${STAGEDIR}${ETCDIR}/services
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup/hosts
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup/services
	@${MKDIR} ${STAGEDIR}${ETCDIR}/backup/ssh
	@${MKDIR} ${STAGEDIR}/var/spool/nagios
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! ( -name *\.orig -o -name *\.bak )")

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -type f | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${ETCDIR} -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${ETCDIR} -type f | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(nagios,nagios,0775) /var/spool/nagios" >> ${TMPPLIST}

.include <bsd.port.mk>

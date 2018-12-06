# $FreeBSD$

PORTNAME=	cacti
PORTVERSION=	0.8.8h
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://www.cacti.net/downloads/
PKGNAMESUFFIX=	88

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rrdtool:databases/rrdtool

USES=		cpe mysql php:web shebangfix
USE_PHP=	mysqli pcre session sockets snmp xml

NO_ARCH=	yes
NO_BUILD=	yes

IGNORE_WITH_PHP=	71 72 73

SUB_FILES=	pkg-message

SHEBANG_FILES=	scripts/3com_cable_modem.pl \
		scripts/diskfree.pl \
		scripts/linux_memory.pl \
		scripts/loadavg.pl \
		scripts/loadavg_multi.pl \
		scripts/ping.pl \
		scripts/query_unix_partitions.pl \
		scripts/unix_processes.pl \
		scripts/unix_tcp_connections.pl \
		scripts/unix_users.pl \
		scripts/weatherbug.pl \
		scripts/webhits.pl

CACTIDIR=	share/cacti
CACTIUSER=	cacti
CACTIGROUP=	cacti

USERS=		${CACTIUSER}
GROUPS=		${CACTIGROUP}

PLIST_SUB+=	CACTIDIR=${CACTIDIR}  CACTIUSER=${CACTIUSER} \
		CACTIGROUP=${CACTIGROUP}
SUB_LIST+=	CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} \
		CACTIGROUP=${CACTIGROUP}

CONFLICTS_INSTALL=	cacti

PORTSCOUT=	limit:^0.*

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete; \
	${MV} ${WRKSRC}/include/config.php ${WRKSRC}/include/config.php.sample
	${RM} -r ${WRKSRC}/log ${WRKSRC}/rra

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${CACTIDIR}
	${MKDIR} ${STAGEDIR}/var/log/cacti
	${MKDIR} ${STAGEDIR}/var/db/cacti/rra
	${MKDIR} ${STAGEDIR}/var/db/cacti/scripts
	${CP} -R ${WRKSRC}/* ${STAGEDIR}/${PREFIX}/${CACTIDIR}
	if [ -f ${PREFIX}/${CACTIDIR}/include/db-settings.php ]; then \
		${ECHO_CMD} "======================================================================="; \
		${ECHO_CMD} "WARNING! You have to move DB settings from"; \
		${ECHO_CMD} "${PREFIX}/${CACTIDIR}/include/db-settings.php file to"; \
		${ECHO_CMD} "${PREFIX}/${CACTIDIR}/include/config.php and remove db-settings.php"; \
	fi

.include <bsd.port.mk>

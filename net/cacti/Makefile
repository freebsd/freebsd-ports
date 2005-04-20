# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.6c
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://www.cacti.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

PATCH_SITES=	http://www.cacti.net/downloads/patches/0.8.6c/
PATCHFILES=	rrd_fetch_negative_numbers.patch \
		no_auth_no_graphs_in_tree_bug.patch \
		device_create_multiple_graphs.patch \
		undefined_index_custom_problem_in_graph_view.patch \
		poller_recache_timeout.patch \
		output_field_name_period.patch \
		ping_sysdescription_to_sysuptime.patch \
		netsnmp_reduce_output_from_loaded_mibs.patch \
		php_snmp_v2.patch \
		config_php_include_order.patch
PATCH_DIST_STRIP=-p1

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		net-snmp-config:${PORTSDIR}/net-mgmt/net-snmp

USE_MYSQL=	yes
USE_PHP=	mysql pcre session xml
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

CACTIDIR?=	share/cacti
CACTIUSER?=	cacti
CACTIGROUP?=	${CACTIUSER}
PLIST_SUB+=	CACTIDIR=${CACTIDIR}

post-extract:
	@${RM} -rf ${WRKSRC}/cactid/.deps

post-patch:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%LOCALBASE%%|${LOCALBASE}| ; \
		s|%%CACTIDIR%%|${CACTIDIR}| ; \
		s|%%CACTIUSER%%|${CACTIUSER}|' > ${PKGMESSAGE}

# Create cacti user/group and clean *.orig files
pre-install:
	@PREFIX=${PREFIX} CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} \
	CACTIGROUP=${CACTIGROUP} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \
	cd ${WRKSRC}; \
	${FIND} . -name \*.orig -delete

do-install:
	@${MKDIR} ${PREFIX}/${CACTIDIR}; \
	${MV} ${WRKSRC}/include/config.php ${WRKSRC}/include/config.php.orig; \
	${CP} -R ${WRKSRC}/* ${PREFIX}/${CACTIDIR}/
	if [ ! -f ${PREFIX}/${CACTIDIR}/include/config.php ]; then \
		${CP} ${PREFIX}/${CACTIDIR}/include/config.php.orig \
			${PREFIX}/${CACTIDIR}/include/config.php; \
	fi; \

# Fix permissions
post-install:
	@PREFIX=${PREFIX} CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} \
	CACTIGROUP=${CACTIGROUP} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.6f
PORTREVISION=	11
CATEGORIES=	net www
MASTER_SITES=	http://www.cacti.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

# Vendor's patches
PATCH_SITES=	http://www.cacti.net/downloads/patches/${PORTVERSION}/
PATCHFILES=	html_mouseover_title.patch \
		multi_field_output_script_server.patch \
		old_net_snmp_command_options.patch \
		poller_invalid_data_sources.patch \
		script_server_buffer_size.patch \
		unix_syslog_compatibility.patch \
		graph_view_preview_mode_filter.patch \
		poller_reindex_cache_orphans.patch \
		safari_zoom.patch \
		ldap_copy_user_problem.patch \
		script_server_file_header.patch

PATCH_DIST_STRIP=-p1

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		net-snmp-config:${PORTSDIR}/net-mgmt/net-snmp

USE_MYSQL=	yes
USE_PHP=	mysql pcre session xml
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-message pkg-install

CACTIDIR?=	share/cacti
CACTIUSER?=	cacti
CACTIGROUP?=	${CACTIUSER}
PLIST_SUB+=	CACTIDIR=${CACTIDIR}
SUB_LIST+=	CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} \
		CACTIGROUP=${CACTIGROUP}

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete; \
	${MV} ${WRKSRC}/include/db-settings.php ${WRKSRC}/include/db-settings.php.orig

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \

do-install:
	@${MKDIR} ${PREFIX}/${CACTIDIR}; \
	${CP} -R ${WRKSRC}/* ${PREFIX}/${CACTIDIR}/; \
	if [ ! -f ${PREFIX}/${CACTIDIR}/include/db-settings.php ]; then \
		${CP} ${PREFIX}/${CACTIDIR}/include/db-settings.php.orig \
			${PREFIX}/${CACTIDIR}/include/db-settings.php; \
	fi

# Fix permissions
post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

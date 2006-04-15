# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.6h
PORTREVISION=	42
CATEGORIES=	net www
MASTER_SITES=	http://www.cacti.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

# Vendor's patches
PATCH_SITES=	http://www.cacti.net/downloads/patches/${PORTVERSION}/
PATCHFILES=	fix_search_session_clear_issue.patch \
		fix_sql_syntax_related_to_default_rra_id.patch \
		nth_percentile_empty_return_set_issue.patch \
		mysql_5x_strict.patch

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

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

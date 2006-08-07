# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.6h.${PATCHLEVEL}
PORTREVISION=	5
CATEGORIES=	net www
MASTER_SITES=	http://www.cacti.net/downloads/
DISTNAME=	${PORTNAME}-${SITEDISTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

# Vendor's patches
PATCH_SITES=	http://www.cacti.net/downloads/patches/${SITEDISTVERSION}/
PATCHFILES=	fix_search_session_clear_issue.patch \
		fix_sql_syntax_related_to_default_rra_id.patch \
		nth_percentile_empty_return_set_issue.patch \
		mysql_5x_strict.patch \
		database_autoincrement_corruption.patch
PATCHLEVEL=	5
SITEDISTVERSION=	${PORTVERSION:S/.${PATCHLEVEL}//}

PATCH_DIST_STRIP=-p1

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool

USE_MYSQL=	yes
USE_PHP=	mysql pcre session snmp xml
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

OPTIONS=	PLUGIN "Enable plugin support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PLUGIN)
EXTRA_PATCHES=	${FILESDIR}/extrapatch-plugins

PLIST_SUB+=	PLUGIN=""
.else
PLIST_SUB+=	PLUGIN="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete; \
	${MV} ${WRKSRC}/include/db-settings.php ${WRKSRC}/include/db-settings.php.orig
	${MV} ${WRKSRC}/include/config.php ${WRKSRC}/include/config.php.orig

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \

do-install:
	@${MKDIR} ${PREFIX}/${CACTIDIR}; \
	${CP} -R ${WRKSRC}/* ${PREFIX}/${CACTIDIR}/; \
	if [ ! -f ${PREFIX}/${CACTIDIR}/include/db-settings.php ]; then \
		${CP} ${PREFIX}/${CACTIDIR}/include/db-settings.php.orig \
			${PREFIX}/${CACTIDIR}/include/db-settings.php; \
	fi
	@if [ ! -f ${PREFIX}/${CACTIDIR}/include/config.php ]; then \
		${CP} ${PREFIX}/${CACTIDIR}/include/config.php.orig \
			${PREFIX}/${CACTIDIR}/include/config.php; \
	fi

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.6j${PATCHLEVEL}
PORTREVISION=	2
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://www.cacti.net/downloads/
DISTFILES=	${PORTNAME}-${SITEDISTVERSION}${EXTRACT_SUFX}

# Vendor's patches
PATCH_SITES=	http://www.cacti.net/downloads/patches/${SITEDISTVERSION}/
PATCHFILES=	ping_php_version4_snmpgetnext.patch \
		tree_console_missing_hosts.patch \
		thumbnail_graphs_not_working.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

PATCHLEVEL=	.3
PATCH_STRIP=	-p1
USE_MYSQL=	yes
USE_PHP=	mysql pcre session sockets snmp xml
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-message pkg-install

CACTIDIR?=	share/cacti
CACTIUSER?=	cacti
CACTIGROUP?=	${CACTIUSER}
WRKSRC=		${WRKDIR}/${PORTNAME}-${SITEDISTVERSION}

OPTIONS=	PLUGIN_ARCH "With plugin architecture" Off

.include <bsd.port.pre.mk>

SITEDISTVERSION=	${PORTVERSION:S/${PATCHLEVEL}$//}

# Extra patches
.if defined(WITH_PLUGIN_ARCH)
MASTER_SITES+=	http://cactiusers.net/downloads/plugins/:plugin
DISTFILES+=	cacti-plugin-arch.tar.gz:plugin
EXTRA_PATCHES+=	${WRKDIR}/${PORTNAME}-plugin-${SITEDISTVERSION}.diff
PLIST_SUB+=	PLUGIN=""
.else
PLIST_SUB+=	PLUGIN="@comment "
.endif

PLIST_SUB+=	CACTIDIR=${CACTIDIR}
SUB_LIST+=	CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} \
		CACTIGROUP=${CACTIGROUP}

.if defined(WITH_PLUGIN_ARCH)
post-extract:
	@${CP} ${WRKDIR}/cacti-plugin-arch/${PORTNAME}-plugin-${SITEDISTVERSION}.diff ${WRKDIR}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete; \
	${MV} ${WRKSRC}/include/db-settings.php ${WRKSRC}/include/db-settings.php.orig
	${MV} ${WRKSRC}/include/config.php ${WRKSRC}/include/config.php.orig

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

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

# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.7f${PATCHLEVEL}
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://www.cacti.net/downloads/
DISTFILES=	${PORTNAME}-${SITEDISTVERSION}${EXTRACT_SUFX}

# Vendor's patches
PATCH_SITES=	http://www.cacti.net/downloads/patches/${SITEDISTVERSION}/
PATCHFILES=
PATCHLEVEL=

PATCH_DIST_STRIP=	-p1

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

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

SITEDISTVERSION=	${PORTVERSION:S/${PATCHLEVEL}$//}

PLIST_SUB+=	CACTIDIR=${CACTIDIR}
SUB_LIST+=	CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} \
		CACTIGROUP=${CACTIGROUP}

.if defined(WITH_PLUGIN_ARCH)
post-extract:
	@${ECHO_CMD} "*************************************************************"
	@${ECHO_CMD} "WARNING! Plugin support is dropped!"
	@${ECHO_CMD} "Remove ${PORT_DBDIR}/${PORTNAME}/options file and try again"
	@${ECHO_CMD} "*************************************************************"
	@exit 1
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete; \
	${MV} ${WRKSRC}/include/config.php ${WRKSRC}/include/config.php.orig

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/${CACTIDIR}; \
	${CP} -R ${WRKSRC}/* ${PREFIX}/${CACTIDIR}/; \
	if [ ! -f ${PREFIX}/${CACTIDIR}/include/config.php ]; then \
		${CP} ${PREFIX}/${CACTIDIR}/include/config.php.orig \
			${PREFIX}/${CACTIDIR}/include/config.php; \
	fi; \
	if [ -f ${PREFIX}/${CACTIDIR}/include/db-settings.php ]; then \
		${ECHO_CMD} "======================================================================="; \
		${ECHO_CMD} "WARNING! You have to move DB settings from"; \
		${ECHO_CMD} "${PREFIX}/${CACTIDIR}/include/db-settings.php file to"; \
		${ECHO_CMD} "${PREFIX}/${CACTIDIR}/include/config.php and remove db-settings.php"; \
	fi

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

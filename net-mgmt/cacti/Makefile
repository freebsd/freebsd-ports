# Created by: Vincent Tantardini <vinc@freebsd-fr.org>
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.8b${PATCHLEVEL}
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://www.cacti.net/downloads/
DISTNAME=	${PORTNAME}-${SITEDISTVERSION}

# Vendor's patches
PATCH_SITES=	http://www.cacti.net/downloads/patches/${SITEDISTVERSION}/
PATCHFILES=
PATCH_DIST_STRIP=	-p1
PATCHLEVEL=

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

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

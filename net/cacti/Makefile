# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.6j${PATCHLEVEL}
PORTREVISION=	0
CATEGORIES=	net www
MASTER_SITES=	http://www.cacti.net/downloads/
DISTNAME=	${PORTNAME}-${SITEDISTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Web-driven graphing interface for RRDTool

# Vendor's patches
PATCH_SITES=	http://www.cacti.net/downloads/patches/${SITEDISTVERSION}/
PATCHFILES=
#PATCHLEVEL=	.4
SITEDISTVERSION=	${PORTVERSION:S/${PATCHLEVEL}$//}
#SITEDISTVERSION=	${PORTVERSION}

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

.include <bsd.port.pre.mk>

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

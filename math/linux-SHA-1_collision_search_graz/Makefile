# Ports collection makefile for:  SHA-1_collision_search_graz
# Date created:			  9/27/2007
# Whom:				  Tuc <freebsd-ports@t-b-o-h.net>
#
# $FreeBSD$
#

PORTNAME=	SHA-1_collision_search_graz
PORTVERSION=	5.35
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://boinc.iaik.tugraz.at/sha1_coll_search/download/
PKGNAMEPREFIX=	linux-
DISTNAME=	sha1_collisionsearch_graz_${PORTVERSION}_i686-pc-linux-gnu
EXTRACT_SUFX=

MAINTAINER=	freebsd-ports@t-b-o-h.com
COMMENT=	Distributed client searching for weakness in SHA-1 hash

DEPRECATED=	Project discontinued
EXPIRATION_DATE=2011-04-07

RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

SHA1_PROJECT=	boinc.iaik.tugraz.at_sha1_coll_search
SHA1_BINARY=	${DISTNAME}

SUB_FILES=	app_info.xml
SUB_LIST=	PORTVERSION="${PORTVERSION}" \
		SHA1_BINARY="${SHA1_BINARY}"

USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386
REINPLACE_ARGS=

PLIST_SUB=	SHA1_BINARY="${SHA1_BINARY}" \
		SHA1_SITE="${SHA1_PROJECT}" \
		BOINC_HOME=${BOINC_HOME}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} 755 ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SHA1_PROJECT}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKSRC}/${SHA1_BINARY} ${BOINC_HOME}/projects/${SHA1_PROJECT}/
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SHA1_PROJECT}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

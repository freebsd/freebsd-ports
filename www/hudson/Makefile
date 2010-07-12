# New ports collection makefile for:	hudson
# Date created:		2008-03-08
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hudson
PORTVERSION=	1.366
CATEGORIES=	www java devel
MASTER_SITES=	https://hudson.dev.java.net/files/documents/2402/151408/
DISTNAME=	hudson
EXTRACT_SUFX=	.war
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	hq@FreeBSD.org
COMMENT=	An extensible continuous integration engine

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

USE_RC_SUBR=	hudson.sh

HUDSON_HOME?=	/var/lib/hudson
HUDSON_USER?=	www
HUDSON_GROUP?=	www

PLIST_FILES=	%%DATADIR%%/${DISTNAME}${EXTRACT_SUFX}
PLIST_DIRS=	%%DATADIR%%
SUB_LIST+=	HUDSON_HOME=${HUDSON_HOME} HUDSON_USER=${HUDSON_USER} HUDSON_GROUP=${HUDSON_GROUP} JAVA_HOME=${JAVA_HOME}

do-install:
	${MKDIR} "${DATADIR}"
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ${DATADIR}/

.include <bsd.port.mk>

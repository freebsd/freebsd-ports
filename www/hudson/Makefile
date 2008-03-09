# New ports collection makefile for:	hudson
# Date created:		2008-03-08
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hudson
PORTVERSION=	1.190
CATEGORIES=	www java devel
MASTER_SITES=	https://hudson.dev.java.net/files/documents/2402/88879/
DISTNAME=	hudson
EXTRACT_SUFX=	.war
EXTRACT_ONLY=

MAINTAINER=	hq@FreeBSD.org
COMMENT=	An extensible continuous integration engine

RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/tomcat6:${PORTSDIR}/www/tomcat6

NO_BUILD=	yes

WEBAPP_SUBDIR=	apache-tomcat6.0/webapps
WEBAPP_DIR=	${PREFIX}/${WEBAPP_SUBDIR}

PLIST_FILES=	${WEBAPP_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WEBAPP_DIR}/

.include <bsd.port.mk>

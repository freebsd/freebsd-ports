# New ports collection makefile for:	fbsdmon
# Date created:		21 January 2012
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	fbsdmon
PORTVERSION=	0.91
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://files.roorback.net/

MAINTAINER=	magik@roorback.net
COMMENT=	Submit system and ports statistics to fbsdmon.org

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		jansson.7:${PORTSDIR}/devel/jansson

SUB_FILES=	600.fbsdmon pkg-message
USE_RC_SUBR=	fbsdmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbsdmon ${PREFIX}/sbin
	${MKDIR} /var/db/fbsdmon
	${MKDIR} ${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/600.fbsdmon ${PREFIX}/etc/periodic/weekly

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

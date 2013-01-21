# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fbsdmon
PORTVERSION=	1.00
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Submit system and ports statistics to fbsdmon.org

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jansson:${PORTSDIR}/devel/jansson

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

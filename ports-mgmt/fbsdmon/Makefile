# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fbsdmon
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Submit system and ports statistics to fbsdmon.org

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libjansson.so:${PORTSDIR}/devel/jansson

SUB_FILES=	600.fbsdmon pkg-message
USE_RC_SUBR=	fbsdmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbsdmon ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}/var/db/fbsdmon
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/600.fbsdmon \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

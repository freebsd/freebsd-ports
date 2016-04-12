# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fbsdmon
PORTVERSION=	1.01
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Submit system and ports statistics to fbsdmon.org

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson

SUB_FILES=	600.fbsdmon pkg-message
USE_RC_SUBR=	fbsdmon

post-patch:
	@${REINPLACE_CMD} '/^LIBS =/s/$$/ -lz/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbsdmon ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}/var/db/fbsdmon
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/600.fbsdmon \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly

.include <bsd.port.mk>

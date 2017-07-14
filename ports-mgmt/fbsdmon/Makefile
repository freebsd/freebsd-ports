# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fbsdmon
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Submit system and ports statistics to fbsdmon.org

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson

DEPRECATED=	no longer maintained, web site it sends data to has been taken over by cybersquatters
EXPIRATION_DATE=2017-09-01

.if !defined(PACKAGE_BUILDING)
IGNORE=		${DEPRECATED}
.endif

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

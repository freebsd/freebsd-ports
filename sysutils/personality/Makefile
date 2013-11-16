# Created by: Andreas Klemm <andreas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	personality
PORTVERSION=	1.0
CATEGORIES=	sysutils
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System configuration management utility to alter system personality

WRKSRC=		${WRKDIR}/src
NO_BUILD=	YES
SUB_FILES=	pkg-message

PLIST_FILES=	man/man8/${PORTNAME}.8.gz sbin/personality

do-extract:
	@ ${RM} -rf ${WRKDIR}
	@ ${MKDIR} ${WRKDIR}
	@ ${CP} -RP ${.CURDIR}/src ${WRKDIR}

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@ ${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>

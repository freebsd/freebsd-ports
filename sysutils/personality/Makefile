# New ports collection makefile for:	personality
# Date created:		25 Mar 2001
# Whom:			Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	personality
PORTVERSION=	1.0
CATEGORIES=	sysutils
DISTFILES=	# none

MAINTAINER=	andreas_and_joe@tao.org.uk
COMMENT=	System configuration management utility to alter system personality

WRKSRC=		${WRKDIR}/src
NO_BUILD=	YES

do-extract:
	@ ${RM} -rf ${WRKDIR}
	@ ${MKDIR} ${WRKDIR}
	@ ${CP} -RP ${.CURDIR}/src ${WRKDIR}

MAN8=		personality.8
PLIST_FILES=	sbin/personality

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/personality ${PREFIX}/sbin
	@ ${INSTALL_DATA} ${WRKSRC}/personality.8 ${PREFIX}/man/man8

post-install:
	@ ${CAT} ${.CURDIR}/pkg-message

.include <bsd.port.mk>

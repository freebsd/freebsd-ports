# New ports collection makefile for: linux-libxml2
# Date created:		2007.09.02
# Whom:			Artem Naluzhnyy <tut@nhamon.com.ua>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.6.19
CATEGORIES=	textproc linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	RPM of libxml2

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>

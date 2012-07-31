# New ports collection makefile for: linux-libxml2
# Date created:		2007.09.02
# Whom:			Artem Naluzhnyy <tut@nhamon.com.ua>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.6.19
PORTREVISION=	2
CATEGORIES=	textproc linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	RPM of libxml2

CONFLICTS=	linux-f8-libxml2-[0-9]* linux-f10-libxml2-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>

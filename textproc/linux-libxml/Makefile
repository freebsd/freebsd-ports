# New ports collection makefile for: linux-libxml
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	1.8.17
PORTREVISION=	4
CATEGORIES=	textproc linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-13

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of libxml

CONFLICTS=	linux-f8-libxml-[0-9]* linux-f10-libxml-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>

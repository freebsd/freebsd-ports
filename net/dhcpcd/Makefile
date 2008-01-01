# New ports collection makefile for:	dhcpcd
# Date created:				30 December 2007
# Whom:					Roy Marples <roy@marples.name>
#
# $FreeBSD$

PORTNAME=		dhcpcd
PORTVERSION=		3.1.8
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	dhcpcd

MAINTAINER=		roy@marples.name
COMMENT=		DHCP client

PLIST_FILES=		sbin/dhcpcd
MAN8=			dhcpcd.8

USE_BZIP2=		yes
USE_RC_SUBR=		dhcpcd

MAKE_ARGS=		INFODIR=/var/db

.include <bsd.port.mk>

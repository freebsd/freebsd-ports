# New ports collection makefile for: linux-libxml
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	1.8.17
PORTREVISION=	0
CATEGORIES=	textproc linux
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	3/i386/os/Fedora/RPMS 3/SRPMS

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES+=	libxml-${PORTVERSION}-11.src.rpm
ALWAYS_KEEP_DISTFILES=  yes
.endif

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of libxml

RPM_SET=	libxml-${PORTVERSION}-11.${ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"

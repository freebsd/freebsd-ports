# New ports collection makefile for:	linux-scim-libs
# Date created:		8 January 2008
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	scim-libs
PORTVERSION=	1.4.4
CATEGORIES=	textproc linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.fc4

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Smart Common Input Method platform, library part, Linux binary

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST_SUB=	LINUX_RPM_ARCH=${LINUX_RPM_ARCH}

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/${LINUX_RPM_ARCH}-redhat-linux-gnu/gtk.immodules

.include <bsd.port.mk>

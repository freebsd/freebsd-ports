# New ports collection makefile for:	textproc/linux-f8-scim-libs
# Date created:				2008-04-15
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	scim-libs
PORTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	textproc linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Smart Common Input Method libraries (Linux Fedora 8)

CONFLICTS=	linux-scim-libs-[0-9]* linux-f10-scim-libs-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	gtk2
LINUX_DIST_VER=	8
RPMVERSION=	7.fc8
USE_LDCONFIG=	yes
SRC_DISTFILES=	scim-${PORTVERSION}-${RPMVERSION}.src.rpm

DESCR=		${.CURDIR}/../scim/pkg-descr

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/${LINUX_RPM_ARCH}-redhat-linux-gnu/gtk.immodules

.include <bsd.port.mk>

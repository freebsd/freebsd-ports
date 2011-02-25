# New ports collection makefile for:	textproc/linux-f10-scim-libs
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	scim-libs
PORTVERSION=	1.4.7
PORTREVISION=	2
CATEGORIES=	textproc linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Smart Common Input Method libraries (Linux Fedora 10)

CONFLICTS=	linux-scim-libs-[0-9]* linux-f8-scim-libs-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	gtk2
LINUX_DIST_VER=	10
RPMVERSION=	35.fc10
USE_LDCONFIG=	yes
SRC_DISTFILES=	scim-${PORTVERSION}-${RPMVERSION}.src.rpm

DESCR=		${.CURDIR}/../scim/pkg-descr

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/${LINUX_RPM_ARCH}-redhat-linux-gnu/gtk.immodules

.include <bsd.port.mk>

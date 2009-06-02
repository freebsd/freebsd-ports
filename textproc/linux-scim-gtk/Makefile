# New ports collection makefile for:	linux-scim-gtk
# Date created:		21 November 2008
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	scim-gtk
PORTVERSION=	# defined below
PORTREVISION=	2
CATEGORIES=	textproc linux
MASTER_SITE_SUBDIR=	# defined below
PKGNAMESUFFIX=	-fc${LINUX_DIST_VER}
DISTNAME=	# defined below

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Smart Common Input Method platform, gtk module, Linux binary

CONFLICTS=	linux-f8-scim-gtk-[0-9]* linux-f10-scim-gtk-[0-9]*

MASTER_SITE_SRC_SUBDIR=	# defined below
SRC_DISTFILES=	scim-${PORTVERSION}-${PORTSUBVERSION}.fc${LINUX_DIST_VER}${SRC_SUFX}

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	gtk2 scimlibs
USE_LDCONFIG=	yes
PLIST_SUB=	LINUX_RPM_ARCH=${LINUX_RPM_ARCH}
MD5_FILE=	${PKGDIR}/distinfo.${LINUX_RPM_ARCH}.fc${LINUX_DIST_VER}

.if defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} == f8
PORTVERSION=	1.4.7
PORTSUBVERSION=	7
LINUX_DIST_VER=	8
DISTNAME=	${PORTNAME}-${PORTVERSION}-${PORTSUBVERSION}.fc${LINUX_DIST_VER}
MASTER_SITE_SUBDIR=	../releases/${LINUX_DIST_VER}/Everything/${LINUX_RPM_ARCH}/os/Packages
MASTER_SITE_SRC_SUBDIR=	../releases/${LINUX_DIST_VER}/Everything/source/SRPMS
.elif defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} == f7
PORTVERSION=	1.4.5
PORTSUBVERSION=	18
LINUX_DIST_VER=	7
DISTNAME=	${PORTNAME}-${PORTVERSION}-${PORTSUBVERSION}.fc${LINUX_DIST_VER}
MASTER_SITE_SUBDIR=	../releases/${LINUX_DIST_VER}/Everything/${LINUX_RPM_ARCH}/os/Fedora
MASTER_SITE_SRC_SUBDIR=	../releases/${LINUX_DIST_VER}/Everything/source/SRPMS
.else
PORTVERSION=	1.4.4
PORTSUBVERSION=	1
DISTNAME=	scim-libs-${PORTVERSION}-${PORTSUBVERSION}.fc${LINUX_DIST_VER}
LINUX_DIST_VER=	4
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS

post-extract:
	cd ${WRKDIR}/usr/lib && ${RM} -rf libscim-* scim-1.0
.endif

.for V in fc4 f7 f8
makesum-${V}:
	${MAKE} PACKAGE_BUILDING=yes OVERRIDE_LINUX_BASE_PORT=${V} makesum
.endfor
makesum-all: makesum-fc4 makesum-f7 makesum-f8

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/${LINUX_RPM_ARCH}-redhat-linux-gnu/gtk.immodules

.include <bsd.port.mk>

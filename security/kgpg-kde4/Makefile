# New ports collection makefile for:	kdeutils3
# Date created:				3 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdeutils
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	0
CATEGORIES?=	misc kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Utilities for the KDE integrated X11 desktop

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
DO_NOT_COMPILE+=kmilo kdepasswd
CONFIGURE_ENV+= DO_NOT_COMPILE="${DO_NOT_COMPILE}"

CONFLICTS=	kgpg-*

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

#klaptop needs APM, which is i386 only 
.if ${MACHINE_ARCH} != "i386"
WITHOUT_KLAPTOP	=yes
.endif # ${MACHINE_ARCH} == "alpha"

.if defined(WITHOUT_KLAPTOP)
DO_NOT_COMPILE+=klaptopdaemon
.else
PLIST_APPEND+=	plist.klaptop
.endif # defined(WITHOUT_KLAPTOP)

# kfloppy is a mostly broken, non-standard, linux-centric pain...
.if !defined(WITH_KFLOPPY)
DO_NOT_COMPILE+=kfloppy
.else
PLIST_APPEND+=	plist.kfloppy
.endif # !defined(WITH_KFLOPPY)

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.post.mk>

# -*-mode: makefile-*-
# New ports collection makefile for:	kdenetwork2
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	2
CATEGORIES?=	net news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Network-related programs and modules for KDE

LIB_DEPENDS=	uu.3:${PORTSDIR}/converters/uulib

CONFLICTS=	mimelib-1.1.*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if !defined(WITHOUT_KTALKD)
UTMP?=	/var/run/utmp
.if exists(${UTMP})
PLIST_APPEND+=	plist.ktalkd
.else
DO_NOT_COMPILE+=	ktalkd
pre-everything::
	@${ECHO_MSG} "===> \"${UTMP}\" was not found."
	@${ECHO_MSG} "===> The talk daemon (ktalkd) will not be built."
.endif # exists(${UTMP})
.else
DO_NOT_COMPILE+=	ktalkd
.endif # !defined(WITHOUT_KTALKD)

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

.include <bsd.port.post.mk>

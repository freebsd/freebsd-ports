# New ports collection makefile for:	klaptopdaemon
# Date created:				July 08 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klaptopdaemon
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdeutils-
DISTNAME=	kdeutils-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Power management utility for KDE

CONFLICTS=	kdeutils-3.1.* kdeutils-3.2.[0-3]

OPTIONS=	ACPI "Contributed ACPI support patch" off

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
USE_AUTOTOOLS=  libtool:15
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdeutils-${PORTVERSION}

USE_LDCONFIG=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include <bsd.port.pre.mk>

.if defined(WITH_ACPI)
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-acpi-support
ONLY_FOR_ARCHS+=amd64
.endif

pre-configure:
	${ECHO_CMD} ${PORTNAME} > ${WRKSRC}/inst-apps

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>

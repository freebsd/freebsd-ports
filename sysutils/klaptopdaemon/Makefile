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
COMMENT=	APM monitor for KDE

OPTIONS=	#no options for amd64

USE_KDELIBS_VER=3

ONLY_FOR_ARCHS=	i386
USE_XORG=	xtst xscrnsaver
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdeutils-${PORTVERSION}

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS=	ACPI "Contributed ACPI support patch" off
.endif

.if ${ARCH} == "amd64"
WITH_ACPI=	yes
.endif

.if defined(WITH_ACPI)
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-acpi-support
ONLY_FOR_ARCHS+=amd64
.endif

pre-configure:
	${ECHO_CMD} ${PORTNAME} > ${WRKSRC}/inst-apps

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>

# New ports collection Makefile for:	filelight
# Date created:				2009-10-09
# Whom:					Rusty Nejdl <rnejdl@ringofsaturn.com>
#
# $FreeBSD$
#

PORTNAME=	filelight
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdeutils-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Map of concentric segmented-rings representing your file system

LATEST_LINK=	${PORTNAME}-kde4

CONFLICTS=	kdeutils-4.6.*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_BZIP2=	yes
DISTINFO_FILE=	${PORTSDIR}/misc/kdeutils4/distinfo
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

.include <bsd.port.mk>

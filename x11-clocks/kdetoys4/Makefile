# New ports collection Makefile for:	kdetoys
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdetoys
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11-clocks kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of entertaining, educational programs for KDE

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

MAN6=	amor.6

.include <bsd.port.mk>

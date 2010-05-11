# New ports collection Makefile for:	kdewebdev
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdewebdev
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Comprehensive html/website development environment

LIB_DEPENDS=	tidy-0.99.0:${PORTSDIR}/www/tidy-lib

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
QT_COMPONENTS=	opengl gui qmake_build moc_build rcc_build uic_build \
		porting_build uic3_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>

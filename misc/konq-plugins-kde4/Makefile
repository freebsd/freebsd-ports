# New ports collection makefile for:	konq-plugins-kde4
# Date created:		2008-07-31
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	konq-plugins
PORTVERSION=	${EXTRA_VER}
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${EXTRA_VER}/src/extragear
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Additonal plugins and features for Konqueror

LIB_DEPENDS=	tidy-0.99.0:${PORTSDIR}/www/tidy-lib

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdebase kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

EXTRA_VER=	4.2.3

.include <bsd.port.mk>

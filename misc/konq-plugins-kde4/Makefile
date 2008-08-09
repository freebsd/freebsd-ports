# New ports collection makefile for:	konq-plugins-kde4
# Date created:		2008-07-31
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	konq-plugins
PORTVERSION=	${EXTRA_VER}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${EXTRA_VER}/src/extragear
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Additonal plugins and features for Konqueror

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdebase kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib
USE_CMAKE=	yes

EXTRA_VER=	4.1.0

.include <bsd.port.mk>

# New ports collection makefile for:    kde3-i18n-nl
# Date created:                         05 April 2002
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n-nl
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	2
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=     stable/${PORTVERSION}/src/kde-i18n
DIST_SUBDIR=    KDE
WRKSRC=		${WRKDIR}/${PORTNAME}

MAINTAINER?=    kde@FreeBSD.org

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>

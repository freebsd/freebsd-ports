# New ports collection makefile for:    kde3-i18n-sv
# Date created:                         05 April 2002
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n-sv
PORTVERSION=	${KDE_VERSION}
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=     stable/${PORTVERSION}/src
DIST_SUBDIR=    KDE
WRKSRC=		${WRKDIR}/${PORTNAME}

MAINTAINER?=    kde@FreeBSD.org

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>

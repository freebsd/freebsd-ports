# New ports collection makefile for:    kde3-i18n-is
# Date created:                         05 April 2002
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	${KDE_VERSION}
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src/kde-i18n
PKGNAMEPREFIX=	is-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KDE3

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext-old

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>

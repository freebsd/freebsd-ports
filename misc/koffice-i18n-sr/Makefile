# New ports collection makefile for:	koffice-i18n-sr
# Date created:                         21 January 2004
# Whom:                                 Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.3.2
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-${PORTVERSION}/src
PKGNAMEPREFIX=	sr-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for koffice

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>

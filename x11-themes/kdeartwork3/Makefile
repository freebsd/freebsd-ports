# New ports collection makefile for:	KDE artwork
# Date created:				20 August 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeartwork
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	x11-wm kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

USE_KDEBASE_VER=3
USE_MESA=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>

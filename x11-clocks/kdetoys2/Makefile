# New ports collection makefile for:	kdetoys2
# Date created:				14 May 2000 02:45:53
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdetoys
PORTVERSION=	2.1.1
CATEGORIES=	x11-clocks kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

USE_KDELIBS_VER=2
MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE}
USE_GMAKE=	yes

.include <bsd.port.mk>

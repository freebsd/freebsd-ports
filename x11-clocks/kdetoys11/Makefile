# New ports collection makefile for:	kdetoys
# Date created:		18 may 1999
# Whom:			imura@af.airnet.ne.jp
#
# $FreeBSD$
#

PORTNAME=	kdetoys
PORTVERSION=	1.1.2
CATEGORIES=	x11-clocks kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/source/bz2

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	"--with-qt-includes=${QTDIR}/include/X11/qt" \
		"--with-extra-includes=${LOCALBASE}/include" \
		"--with-extra-libs=${LOCALBASE}/lib"
CONFIGURE_ENV=	QTDIR=${QTDIR} \
		DO_NOT_COMPILE=mouse

.if defined(PREFIX)
QTDIR?=		${PREFIX}
.else
QTDIR?=		${X11BASE}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:   kwatch
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <zerium@webindex.no>
#
# $Id: Makefile,v 1.7 1998/09/30 02:07:28 jseger Exp $
#

DISTNAME=	kwatch-0.3
CATEGORIES=	misc x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.0/apps/utils

MAINTAINER=	zerium@webindex.no

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>

# New ports collection makefile for:   kwatch
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.3 1998/08/12 06:29:31 asami Exp $
#

DISTNAME=	kwatch-0.3
CATEGORIES=	misc x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= /stable/Beta4/apps/utils

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.1\\.:${PORTSDIR}/x11/kdelibs \
		kdeui\\.1\\.:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>

# New ports collection makefile for:   klyx
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.2 1998/05/25 14:30:41 tg Exp $
#

DISTNAME=	klyx-0.9.3
CATEGORIES=	print kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= /unstable/apps/office

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11-toolkits/qt \
		kdecore\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kfile\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CXXFLAGS)" \
		INSTALL_SCRIPT="$(INSTALL_SCRIPT)"

.include <bsd.port.mk>

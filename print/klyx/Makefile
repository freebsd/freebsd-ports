# New ports collection makefile for:   klyx
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.3 1998/08/07 23:56:46 asami Exp $
#

DISTNAME=	klyx-0.9.3
CATEGORIES=	print kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= /unstable/apps/office

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	kdecore\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kfile\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CXXFLAGS)" \
		INSTALL_SCRIPT="$(INSTALL_SCRIPT)"

.include <bsd.port.mk>

# New ports collection makefile for:   klyx
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.6 1998/09/30 02:07:27 jseger Exp $
#

DISTNAME=	klyx-0.9.3
CATEGORIES=	print kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= /unstable/apps/office

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs \
		kfm.1:${PORTSDIR}/x11/kdelibs \
		kfile.1:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CXXFLAGS)" \
		INSTALL_SCRIPT="$(INSTALL_SCRIPT)"

.include <bsd.port.mk>

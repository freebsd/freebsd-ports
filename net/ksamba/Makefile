# New ports collection makefile for:   ksamba
# Version required:    Beta4
# Date created:        18 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.6 1998/09/30 02:07:28 jseger Exp $
#

DISTNAME=	ksamba-0.3.3
CATEGORIES=	x11 kde net
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= /unstable/apps/network

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs \
		kfm.1:${PORTSDIR}/x11/kdelibs \
		kfile.1:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>

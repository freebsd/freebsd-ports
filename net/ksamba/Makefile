# New ports collection makefile for:   ksamba
# Version required:    Beta4
# Date created:        18 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

DISTNAME=	ksamba-0.3.3
CATEGORIES=	kde net
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/network

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11 \
		kfm.3:${PORTSDIR}/x11/kdelibs11 \
		kfile.3:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>

# New ports collection makefile for:   klyx
# Version required:    0.9.8a
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.9 1998/12/25 17:51:27 steve Exp $
#

DISTNAME=	klyx-0.9.8a
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR= unstable/apps/office

MAINTAINER=	tom@eborcom.com

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11 \
		kfm.2:${PORTSDIR}/x11/kdelibs11 \
		kfile.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include <bsd.port.mk>

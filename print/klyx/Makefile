# New ports collection makefile for:   klyx
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.5 1998/08/25 10:04:58 asami Exp $
#

DISTNAME=	klyx-0.9.3
CATEGORIES=	print kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= /unstable/apps/office

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	kdecore\\.1\\.:${PORTSDIR}/x11/kdelibs \
		kdeui\\.1\\.:${PORTSDIR}/x11/kdelibs \
		kfm\\.1\\.:${PORTSDIR}/x11/kdelibs \
		kfile\\.1\\.:${PORTSDIR}/x11/kdelibs

BROKEN_ELF=	depends on kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CXXFLAGS)" \
		INSTALL_SCRIPT="$(INSTALL_SCRIPT)"

.include <bsd.port.mk>

# New ports collection makefile for:   klyx
# Version required:    0.10.0
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.10 1999/05/24 02:31:48 steve Exp $
#

DISTNAME=	klyx-0.10.0
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR= unstable/apps/office

MAINTAINER=	tom@eborcom.com

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include <bsd.port.mk>

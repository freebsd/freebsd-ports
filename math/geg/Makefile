# New ports collection makefile for: geg
# Version required:    0.15.0
# Date created:        8 Aug 1998
# Whom:                rom
#
# $Id: Makefile,v 1.3 1998/09/22 22:55:54 asami Exp $
#

DISTNAME=	geg-0.15.0
CATEGORIES=	math
MASTER_SITES=	http://www.geocities.com/SiliconValley/Park/2030/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="${LOCALBASE}/lib"

.include <bsd.port.mk>

# New ports collection makefile for:		geg
# Version required:				0.99.0
# Date created:					8 Aug 1998
# Whom:						rom
#
# $Id: Makefile,v 1.6 1998/12/22 07:52:51 asami Exp $
#

DISTNAME=	geg-0.99.0
CATEGORIES=	math
MASTER_SITES=	http://www.geocities.com/SiliconValley/Park/2030/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"

.include <bsd.port.mk>

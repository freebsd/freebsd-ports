# New ports collection makefile for:    licq
# Version required:                     0.34
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman
#
# $Id: Makefile,v 1.1.1.1 1998/07/09 16:01:50 eivind Exp $
#

DISTNAME=	licq-0.34
CATEGORIES=	net
MASTER_SITES=	http://pages.infinit.net/fairoff/licq/

MAINTAINER=	brianfeldman@hotmail.com

LIB_DEPENDS=	qt\\.1\\.33:${PORTSDIR}/x11-toolkits/qt133

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/X11/qt --with-qt-libs=${X11BASE}/lib

.include <bsd.port.mk>

# New ports collection makefile for:    licq
# Version required:                     0.34
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman
#
# $Id: Makefile,v 1.3 1998/08/09 01:25:53 steve Exp $
#

DISTNAME=	licq-0.34
CATEGORIES=	net
MASTER_SITES=	http://pages.infinit.net/fairoff/licq/

MAINTAINER=	brianfeldman@hotmail.com

USE_QT=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/X11/qt --with-qt-libs=${X11BASE}/lib

.include <bsd.port.mk>

# New ports collection makefile for:    licq
# Version required:                     0.34
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman
#
# $Id: Makefile,v 1.4 1998/08/12 06:29:32 asami Exp $
#

DISTNAME=	licq-0.44
CATEGORIES=	net
MASTER_SITES=	http://pages.infinit.net/fairoff/licq/

MAINTAINER=	green@unixhelp.org

FETCH_BEFORE_ARGS=	-b

USE_QT=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/X11/qt --with-qt-libs=${X11BASE}/lib

MAN1=		licq.1

.include <bsd.port.mk>

# New ports collection makefile for:	xgfe
# Version required:    2.0
# Date created:        24 March 1998
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.8 1998/11/08 20:27:52 mph Exp $
#

DISTNAME=		xgfe-2.0
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/visualization

MAINTAINER=	mph@freebsd.org

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_QT=		yes
USE_X_PREFIX=	yes

MAKE_ENV=	X11BASE=$(X11BASE) PREFIX=$(PREFIX)
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=$(NOPORTDOCS)
.endif

WRKSRC=		$(WRKDIR)/$(DISTNAME)/source

post-extract:
	cd $(WRKSRC) && ${RM} Makefile && ${LN} -s Makefile.freebsd-gcc Makefile

.include <bsd.port.mk>

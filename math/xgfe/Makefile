# New ports collection makefile for:	xgfe
# Version required:    2.0
# Date created:        24 March 1998
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.5 1998/08/05 09:31:30 asami Exp $
#

DISTNAME=	xgfe-2.0
CATEGORIES=	math
MASTER_SITES=	http://www2.msstate.edu/~dmi1/xgfe/download/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	qt\\.1\\.3:${PORTSDIR}/x11-toolkits/qt
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_X_PREFIX=	yes

MAKE_ENV=	X11BASE=$(X11BASE) PREFIX=$(PREFIX)
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=$(NOPORTDOCS)
.endif

WRKSRC=		$(WRKDIR)/$(DISTNAME)/source

post-extract:
	cd $(WRKSRC) && ${RM} Makefile && ${LN} -s Makefile.freebsd-gcc Makefile

.include <bsd.port.mk>

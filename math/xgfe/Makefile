# New ports collection makefile for:	xgfe
# Version required:    2.0
# Date created:        24 March 1998
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

DISTNAME=		xgfe-2.0
CATEGORIES=		math
MASTER_SITES=		http://www.freebsd.org/~mph/distfiles/

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

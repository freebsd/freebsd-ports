# New ports collection makefile for:	xgfe
# Date created:        24 March 1998
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xgfe
PORTVERSION=	2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mph

MAINTAINER=	mph@freebsd.org

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_QT_VER=	1
USE_X_PREFIX=	yes

MAKE_ENV=	X11BASE=$(X11BASE) PREFIX=$(PREFIX)
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=$(NOPORTDOCS)
.endif

WRKSRC=		$(WRKDIR)/$(DISTNAME)/source

post-extract:
	cd $(WRKSRC) && ${RM} Makefile && ${LN} -s Makefile.freebsd-gcc Makefile

.include <bsd.port.mk>

# New ports collection makefile for:	xgfe
# Date created:        24 March 1998
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xgfe
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	graphics/gnuplot/contrib

MAINTAINER=	mph@freebsd.org
COMMENT=	An X11 front-end for Gnuplot

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_QT_VER=	3
USE_X_PREFIX=	yes

MAKE_ENV+=	DOCSDIR=$(DOCSDIR) PTHREAD_CFLAGS="$(PTHREAD_CFLAGS)" \
		PTHREAD_LIBS="$(PTHREAD_LIBS)"
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=$(NOPORTDOCS)
.endif

WRKSRC=		$(WRKDIR)/$(DISTNAME)/source

post-extract:
	@cd $(WRKSRC) && ${LN} -sf Makefile.freebsd-gcc Makefile

.include <bsd.port.mk>

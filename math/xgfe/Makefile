# New ports collection makefile for:	xgfe
# Date created:        24 March 1998
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xgfe
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	graphics/gnuplot/contrib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 front-end for Gnuplot

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_QT_VER=	3

MAKE_ENV+=	DOCSDIR=$(DOCSDIR) PTHREAD_CFLAGS="$(PTHREAD_CFLAGS)" \
		PTHREAD_LIBS="$(PTHREAD_LIBS)" QT_PREFIX="${QT_PREFIX}"
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=$(NOPORTDOCS)
.endif

WRKSRC=		$(WRKDIR)/$(DISTNAME)/source

post-extract:
	@cd $(WRKSRC) && ${LN} -sf Makefile.freebsd-gcc Makefile

.include <bsd.port.mk>

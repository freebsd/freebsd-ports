# New ports collection makefile for:	EmiClock
# Version required:	1.0.4
# Date created:		15 March 1995
# Whom:			Nobuhiro Yasutomi
#
# $Id: Makefile,v 1.11 1998/09/21 01:39:09 steve Exp $
#

DISTNAME=	emiclock-1.0.4
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.plaza.hitachi-sk.co.jp/pub/EmiClock/X11/

MAINTAINER=	nobu@psrc.isac.co.jp

USE_IMAKE=	yes
MAN1=		emiclock.1

LANGRES=	resources/R6/EUC/EmiClock.ad
LANGDIR=	$(X11BASE)/lib/X11/ja_JP.EUC/app-defaults
EMICLOCKDIR=	$(X11BASE)/lib/X11/EmiClock
COPYRIGHTS=	COPYRIGHT COPYRIGHT.en

pre-install:
	@if [ ! -d $(EMICLOCKDIR) ] ; then mkdir -p $(EMICLOCKDIR); fi
	@if [ ! -d $(LANGDIR) ] ; then mkdir -p $(LANGDIR); fi
	cd $(WRKSRC); install -c -m 0444 $(LANGRES) $(LANGDIR)/EmiClock
	cd $(WRKSRC); install -c -m 0444 $(COPYRIGHTS) $(EMICLOCKDIR)
#	cd $(WRKSRC); make install.man

.include <bsd.port.mk>

# New ports collection makefile for:	EmiClock
# Version required:	1.0.2
# Date created:		15 March 1995
# Whom:			Nobuhiro Yasutomi
#
# $Id: Makefile,v 1.4 1995/04/12 20:31:01 asami Exp $
#

DISTNAME=	EmiClock-1.0.2
PKGNAME=	emiclock-1.0.2
CATEGORIES+=	x11
MASTER_SITES=	ftp://theta.iis.u-tokyo.ac.jp/pub1/X/contrib/applications/ \
		ftp://sunsite.unc.edu/pub/X11/contrib/applications/

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes

LANGRES=	resources/R6/EUC/EmiClock.ad
LANGDIR=	$(X11BASE)/lib/X11/ja_JP.EUC/app-defaults
EMICLOCKDIR=	$(X11BASE)/lib/X11/EmiClock
COPYRIGHTS=	COPYRIGHT COPYRIGHT.E

pre-install:
	@if [ ! -d $(EMICLOCKDIR) ] ; then mkdir -p $(EMICLOCKDIR); fi
	@if [ ! -d $(LANGDIR) ] ; then mkdir -p $(LANGDIR); fi
	cd $(WRKSRC); install -c -m 0444 $(LANGRES) $(LANGDIR)/EmiClock
	cd $(WRKSRC); install -c -m 0444 $(COPYRIGHTS) $(EMICLOCKDIR)
#	cd $(WRKSRC); make install.man

.include <bsd.port.mk>

# New ports collection makefile for:	EmiClock
# Date created:		15 March 1995
# Whom:			Nobuhiro Yasutomi
#
# $FreeBSD$
#

PORTNAME=	emiclock
PORTVERSION=	2.0.2
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.noge.com/pub/EmiClock/X11/

MAINTAINER=	koba@noge.com

.if ${MACHINE_ARCH} != "i386"
PLIST=		${PKGDIR}/pkg-plist.nosound
.endif

USE_IMAKE=	yes
MAN1=		emiclock.1

LANGRES=	resources/R6/EUC/EmiClock.ad
LANGDIR=	$(X11BASE)/lib/X11/ja_JP.EUC/app-defaults
EMICLOCKDIR=	$(X11BASE)/lib/X11/EmiClock
COPYRIGHTS=	COPYRIGHT COPYRIGHT.en

pre-install:
	@if [ ! -d $(EMICLOCKDIR) ] ; then ${MKDIR} $(EMICLOCKDIR); fi
	@if [ ! -d $(LANGDIR) ] ; then ${MKDIR} $(LANGDIR); fi
	cd $(WRKSRC); ${INSTALL_DATA} -c -m 0444 $(LANGRES) $(LANGDIR)/EmiClock
	cd $(WRKSRC); ${INSTALL_DATA} -c -m 0444 $(COPYRIGHTS) $(EMICLOCKDIR)
#	cd $(WRKSRC); make install.man

.include <bsd.port.mk>

# New ports collection makefile for:	Xfstt
# Version required:	1.1
# Date created:		11 September 1998
# Whom:			jabley@clear.co.nz
#
# $FreeBSD$
#

DISTNAME=	xfstt-1.1
CATEGORIES=	x11-servers
MASTER_SITES=	$(MASTER_SITE_SUNSITE)
MASTER_SITE_SUBDIR=	X11/fonts

MAINTAINER=	rip@pinetec.co.za

USE_X_PREFIX=	yes
MAN1=		xfstt.1

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/xfstt $(PREFIX)/bin
	$(INSTALL_MAN) $(WRKSRC)/xfstt.1x $(PREFIX)/man/man1/xfstt.1

post-install:
	strip $(PREFIX)/bin/xfstt
.if !defined(NOPORTDOCS)
	$(MKDIR) $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/FAQ $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/CHANGES $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/INSTALL $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/THANKS.txt $(PREFIX)/share/doc/xfstt
.endif

.include <bsd.port.mk>

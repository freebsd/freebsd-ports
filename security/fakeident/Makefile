# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	fakeident
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Tool that replies with a standard answer to incoming identd requests

NO_STAGE=	yes
do-build:
	@cd $(WRKSRC); \
	$(CC) $(CFLAGS) -o identd identd.c
	@echo ""
	@echo "*** CAUTION:"
	@echo ""
	@echo "This port may overwrite any other identd daemon"
	@echo "you have installed. It is recommended that any"
	@echo "other identd ports be deinstalled prior to"
	@echo "running make install for this port."
	@echo ""

do-install:
	$(INSTALL_SCRIPT) $(WRKSRC)/identd $(PREFIX)/sbin
	$(INSTALL_SCRIPT) $(FILESDIR)/fakeident.sh $(PREFIX)/etc/rc.d

.include <bsd.port.mk>

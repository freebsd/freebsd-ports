# New ports collection makefile for:	proxy-connect
# Date created:				22 Jun 2005
# Whom:					alfred@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	proxy-connect
PORTVERSION=	100
CATEGORIES=	net
MASTER_SITES=	http://www.exit2shell.com/~skreuzer/distfiles/ \
				http://www.atarininja.org/distfiles/
DISTNAME=	$(PORTNAME)-$(PORTVERSION)

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Command to make network connections via SOCKS and HTTPS proxies

USE_BZIP2=	yes

EXENAME=	$(PORTNAME)

PLIST_FILES=	sbin/$(EXENAME)

do-build:
		cd $(WRKSRC) && $(CC) $(CFLAGS) -o $(EXENAME) connect.c

do-install:
		$(INSTALL_PROGRAM) \
			$(WRKSRC)/$(EXENAME) $(PREFIX)/sbin/$(EXENAME)

.include <bsd.port.mk>

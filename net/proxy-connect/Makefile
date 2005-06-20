# New ports collection makefile for:	replay
# Date created:				22 Jun 2005
# Whom:					alfred@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	proxy-connect
PORTVERSION=	1.68
CATEGORIES=	net
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/proxy-connect/
DISTNAME=	$(PORTNAME)-$(PORTVERSION)

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	A socks4, socks5 and http proxy tool

USE_BZIP2=	yes

EXENAME=	$(PORTNAME)

PLIST_FILES=	sbin/$(EXENAME)

do-build:
		cd $(WRKSRC) && $(CC) $(CFLAGS) -o $(EXENAME) connect.c

do-install:
		$(INSTALL_PROGRAM) \
			$(WRKSRC)/$(EXENAME) $(PREFIX)/sbin/$(EXENAME)

.include <bsd.port.mk>

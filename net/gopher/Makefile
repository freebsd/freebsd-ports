# New ports collection makefile for:	gopher
# Version required:	2.3
# Date created:		11 Dec 1994
# Whom:			ats (original)
#
# $Id: Makefile,v 1.7 1996/11/17 01:48:15 max Exp $
#

DISTNAME=	gopher2_3
PKGNAME=	gopher-2.3
CATEGORIES=	net
MASTER_SITES=	ftp://boombox.micro.umn.edu/pub/gopher/Unix/

MAINTAINER=	ports@FreeBSD.org

DATADIR=	$(PREFIX)/gopher-data
CONFIGURE_ENV=	LIBS='-lcompat -lcrypt'
CONFIGURE_ARGS=	--enable-datadir=$(DATADIR) --disable-debug --with-x
GNU_CONFIGURE=	yes

MAN1=	gopher.1 gophfilt.1
MAN5=	gopherd.conf.5 gopherrc.5
MAN8=	gopherd.8 gopherindex.8

pre-install:
	$(MKDIR) $(DATADIR)

.include <bsd.port.mk>

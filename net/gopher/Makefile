# New ports collection makefile for:	gopher
# Version required:	2.3
# Date created:		11 Dec 1994
# Whom:			ats (original)
#
# $FreeBSD$
#

DISTNAME=	gopher2_3
PKGNAME=	gopher-2.3
CATEGORIES=	net
MASTER_SITES=	ftp://boombox.micro.umn.edu/pub/gopher/Unix/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=  /nonexistent:${PORTSDIR}/net/wais:build

DATADIR=	$(PREFIX)/gopher-data
WaisTop=	$(PORTSDIR)/net/wais/work/freeWAIS-0.5
CONFIGURE_ENV=	LIBS='-lcompat -lcrypt'
CONFIGURE_ARGS=	--enable-datadir=$(DATADIR) --disable-debug --enable-locale
GNU_CONFIGURE=	yes

MAN1=	gopher.1 gophfilt.1
MAN5=	gopherd.conf.5 gopherrc.5
MAN8=	gopherd.8 gopherindex.8

pre-configure:
# This ones are for FreeWAIS-0.4 and >
	${LN} -s ${WaisTop}/include $(WaisTop)/ir
	${LN} -s ${WaisTop}/src/client/ui $(WaisTop)
	${LN} -s ${WaisTop}/bin $(WRKSRC)
# This is the new configuration method
	${LN} -s ${WaisTop} $(WRKSRC)/wais
pre-install:
	$(MKDIR) $(DATADIR)

.include <bsd.port.mk>

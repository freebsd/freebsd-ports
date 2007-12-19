# New ports collection makefile for:	greylite
# Date created:		2007-12-11
# Whom:			Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PORTNAME=	greylite
DISTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://mij.oltrelinux.com/net/greylite/

MAINTAINER=	mij@bitchx.it
COMMENT=	An efficient greylisting module for qmail

USE_BZIP2=	yes
USE_SQLITE=	3
PLIST_FILES=	bin/greylite

MAN8=		greylite.8
MANCOMPRESSED=	yes

OPTIONS=	GEOIP	"Enable support for GeoIP in suspicion rules" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GEOIP)
LIB_DEPENDS+=	GeoIP:$(PORTSDIR)/net/GeoIP
MAKE_ARGS+=	WITH_GEOIP=yep
.endif

post-patch:
	${CP} ${WRKSRC}/Makefile.bsdmake ${WRKSRC}/Makefile

do-build:
	$(MAKE) -C $(WRKSRC) $(MAKE_ARGS)

post-install:
	@$(CAT) pkg-message

.include <bsd.port.post.mk>
